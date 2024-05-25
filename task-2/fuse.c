#define FUSE_USE_VERSION 30

#include <fuse.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <pwd.h>
#include <openssl/bio.h>
#include <openssl/evp.h>
#include <openssl/buffer.h>

static const char *target_path = "task-2/target";

static int is_owner(const char *path) {
    char full_path[1024];
    struct stat st;

    snprintf(full_path, sizeof(full_path), "%s%s", target_path, path);
    if (stat(full_path, &st) == -1) {
        return 0;
    }

    uid_t uid = getuid();
    return st.st_uid == uid;
}

static char* base64_encode(const char* input, int length) {
    BIO *bmem, *b64;
    BUF_MEM *bptr;
    char *buff;

    b64 = BIO_new(BIO_f_base64());
    bmem = BIO_new(BIO_s_mem());
    b64 = BIO_push(b64, bmem);
    BIO_write(b64, input, length);
    BIO_flush(b64);
    BIO_get_mem_ptr(b64, &bptr);

    buff = (char *)malloc(bptr->length + 1);
    memcpy(buff, bptr->data, bptr->length);
    buff[bptr->length] = 0;

    BIO_free_all(b64);

    return buff;
}

static char* base64_decode(const char* input, int length, int* out_length) {
    BIO *b64, *bmem;
    char *buffer = (char *)malloc(length);
    memset(buffer, 0, length);

    b64 = BIO_new(BIO_f_base64());
    bmem = BIO_new_mem_buf(input, length);
    bmem = BIO_push(b64, bmem);
    *out_length = BIO_read(bmem, buffer, length);

    BIO_free_all(bmem);

    return buffer;
}

static int fuse_example_getattr(const char *path, struct stat *stbuf) {
    int res = 0;
    char full_path[1024];

    snprintf(full_path, sizeof(full_path), "%s%s", target_path, path);
    res = lstat(full_path, stbuf);

    if (res == -1)
        return -errno;

    return 0;
}

static int fuse_example_readdir(const char *path, void *buf, fuse_fill_dir_t filler, off_t offset, struct fuse_file_info *fi) {
    DIR *dp;
    struct dirent *de;
    char full_path[1024];

    snprintf(full_path, sizeof(full_path), "%s%s", target_path, path);
    dp = opendir(full_path);
    if (dp == NULL)
        return -errno;

    filler(buf, ".", NULL, 0);
    filler(buf, "..", NULL, 0);
    while ((de = readdir(dp)) != NULL) {
        struct stat st;
        memset(&st, 0, sizeof(st));
        st.st_ino = de->d_ino;
        st.st_mode = de->d_type << 12;
        if (filler(buf, de->d_name, &st, 0))
            break;
    }

    closedir(dp);
    return 0;
}

static int fuse_example_open(const char *path, struct fuse_file_info *fi) {
    int res;
    char full_path[1024];

    snprintf(full_path, sizeof(full_path), "%s%s", target_path, path);
    res = open(full_path, fi->flags);
    if (res == -1)
        return -errno;

    close(res);
    return 0;
}

static int fuse_example_read(const char *path, char *buf, size_t size, off_t offset, struct fuse_file_info *fi) {
    int fd;
    int res;
    char full_path[1024];
    char *file_buf = (char *)malloc(size);

    snprintf(full_path, sizeof(full_path), "%s%s", target_path, path);
    fd = open(full_path, O_RDONLY);
    if (fd == -1)
        return -errno;

    res = pread(fd, file_buf, size, offset);
    if (res == -1) {
        res = -errno;
    } else {
        if (is_owner(path)) {
            int decoded_len;
            char *decoded_buf = base64_decode(file_buf, res, &decoded_len);
            memcpy(buf, decoded_buf, decoded_len);
            res = decoded_len;
            free(decoded_buf);
        } else {
            char *encoded_buf = base64_encode(file_buf, res);
            int encoded_len = strlen(encoded_buf);
            memcpy(buf, encoded_buf, encoded_len);
            res = encoded_len;
            free(encoded_buf);
        }
    }

    free(file_buf);
    close(fd);
    return res;
}

static int fuse_example_write(const char *path, const char *buf, size_t size, off_t offset, struct fuse_file_info *fi) {
    int fd;
    int res;
    char full_path[1024];
    char *encoded_buf = NULL;

    snprintf(full_path, sizeof(full_path), "%s%s", target_path, path);
    fd = open(full_path, O_WRONLY);
    if (fd == -1)
        return -errno;

    if (is_owner(path)) {
        int encoded_len;
        encoded_buf = base64_decode(buf, size, &encoded_len);
        res = pwrite(fd, encoded_buf, encoded_len, offset);
        free(encoded_buf);
    } else {
        res = pwrite(fd, buf, size, offset);
    }

    if (res == -1)
        res = -errno;

    close(fd);
    return res;
}

static int fuse_example_mkdir(const char *path, mode_t mode) {
    if (!is_owner(path)) {
        return -EACCES;
    }

    char full_path[1024];
    snprintf(full_path, sizeof(full_path), "%s%s", target_path, path);
    return mkdir(full_path, mode);
}

static int fuse_example_rmdir(const char *path) {
    if (!is_owner(path)) {
        return -EACCES;
    }

    char full_path[1024];
    snprintf(full_path, sizeof(full_path), "%s%s", target_path, path);
    return rmdir(full_path);
}

static int fuse_example_unlink(const char *path) {
    if (!is_owner(path)) {
        return -EACCES;
    }

    char full_path[1024];
    snprintf(full_path, sizeof(full_path), "%s%s", target_path, path);
    return unlink(full_path);
}

static int fuse_example_rename(const char *from, const char *to) {
    if (!is_owner(from) || !is_owner(to)) {
        return -EACCES;
    }

    char full_from[1024];
    char full_to[1024];
    snprintf(full_from, sizeof(full_from), "%s%s", target_path, from);
    snprintf(full_to, sizeof(full_to), "%s%s", target_path, to);
    return rename(full_from, full_to);
}

static struct fuse_operations fuse_example_oper = {
    .getattr = fuse_example_getattr,
    .readdir = fuse_example_readdir,
    .open = fuse_example_open,
    .read = fuse_example_read,
    .write = fuse_example_write,
    .mkdir = fuse_example_mkdir,
    .rmdir = fuse_example_rmdir,
    .unlink = fuse_example_unlink,
    .rename = fuse_example_rename,
};

int main(int argc, char *argv[]) {
    return fuse_main(argc, argv, &fuse_example_oper, NULL);
}
