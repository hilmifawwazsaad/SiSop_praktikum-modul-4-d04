#define FUSE_USE_VERSION 26
#include <fuse.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <openssl/evp.h>

static const char *target_path = "/home/andi/target";

static int encode_base64(const unsigned char *input, int length, char *output) {
    EVP_ENCODE_CTX *ctx = EVP_ENCODE_CTX_new();
    EVP_EncodeInit(ctx);
    int outlen;
    EVP_EncodeUpdate(ctx, (unsigned char*)output, &outlen, input, length);
    int tmplen;
    EVP_EncodeFinal(ctx, (unsigned char*)output + outlen, &tmplen);
    outlen += tmplen;
    EVP_ENCODE_CTX_free(ctx);
    return outlen;
}

static int decode_base64(const char *input, int length, unsigned char *output) {
    EVP_ENCODE_CTX *ctx = EVP_ENCODE_CTX_new();
    EVP_DecodeInit(ctx);
    int outlen;
    EVP_DecodeUpdate(ctx, output, &outlen, (unsigned char*)input, length);
    int tmplen;
    EVP_DecodeFinal(ctx, output + outlen, &tmplen);
    outlen += tmplen;
    EVP_ENCODE_CTX_free(ctx);
    return outlen;
}

static int custom_getattr(const char *path, struct stat *stbuf) {
    int res = 0;
    memset(stbuf, 0, sizeof(struct stat));

    char full_path[1024];
    sprintf(full_path, "%s%s", target_path, path);

    res = lstat(full_path, stbuf);
    if (res == -1)
        return -errno;

    return 0;
}

static int custom_readdir(const char *path, void *buf, fuse_fill_dir_t filler, off_t offset, struct fuse_file_info *fi) {
    char full_path[1024];
    sprintf(full_path, "%s%s", target_path, path);

    DIR *dp = opendir(full_path);
    if (dp == NULL)
        return -errno;

    struct dirent *de;
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

static int custom_open(const char *path, struct fuse_file_info *fi) {
    char full_path[1024];
    sprintf(full_path, "%s%s", target_path, path);

    int res = open(full_path, fi->flags);
    if (res == -1)
        return -errno;

    close(res);
    return 0;
}

static int custom_read(const char *path, char *buf, size_t size, off_t offset, struct fuse_file_info *fi) {
    char full_path[1024];
    sprintf(full_path, "%s%s", target_path, path);

    int fd = open(full_path, O_RDONLY);
    if (fd == -1)
        return -errno;

    unsigned char *read_buf = malloc(size);
    int res = pread(fd, read_buf, size, offset);
    if (res == -1) {
        res = -errno;
    } else {
        res = decode_base64((char*)read_buf, res, (unsigned char*)buf);
    }

    close(fd);
    free(read_buf);
    return res;
}

static int custom_write(const char *path, const char *buf, size_t size, off_t offset, struct fuse_file_info *fi) {
    char full_path[1024];
    sprintf(full_path, "%s%s", target_path, path);

    int fd = open(full_path, O_WRONLY);
    if (fd == -1)
        return -errno;

    char *encoded_buf = malloc(2 * size);
    int encoded_size = encode_base64((unsigned char*)buf, size, encoded_buf);

    int res = pwrite(fd, encoded_buf, encoded_size, offset);
    if (res == -1)
        res = -errno;

    close(fd);
    free(encoded_buf);
    return res;
}

static struct fuse_operations custom_oper = {
    .getattr = custom_getattr,
    .readdir = custom_readdir,
    .open = custom_open,
    .read = custom_read,
    .write = custom_write,
};

int main(int argc, char *argv[]) {
    return fuse_main(argc, argv, &custom_oper, NULL);
}
