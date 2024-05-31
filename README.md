[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/J5rciaaA)
<div align=center>

|    NRP     |      Name      |
| :--------: | :------------: |
| 5025221000 | Student 1 Name |
| 5025221000 | Student 2 Name |
| 5025221103 | Hilmi Fawwaz Sa'ad |

# Praktikum Modul 4 _(Module 4 Lab Work)_

</div>

### Daftar Soal _(Task List)_

- [Task 1 - TrashOps](/task-1/)

- [Task 2 - Fu53enC0d3D==](/task-2/)

- [Task 3 - MengOS](/task-3/)

### Laporan Resmi Praktikum Modul 4 _(Module 4 Lab Work Report)_

Tulis laporan resmi di sini!

_Write your lab work report here!_

## 1️⃣ Soal 1
### Problem 1a
Kode untuk membuat filesystem diletakkan pada trash.c. Anda harus menggunakan fungsi getattr, readdir, read, unlink, rmdir, rename, mkdir, chown, dan chmod pada struct fuse_operations. Dibebaskan jika ingin menambahkan fungsi lain selain 9 fungsi diatas

**Jawab**

[Jawab Disini]

### Problem 1b
Ketika menggunakan perintah rm atau rmdir untuk file atau direktori yang berada diluar direktori trash, maka file atau direktori tersebut akan dipindahkan ke direktori trash dan menjadi tidak dapat diread, write, dan execute baik oleh pemilik, grup, maupun user lainnya

Barulah ketika perintah rm atau rmdir digunakan untuk file atau direktori yang berada di dalam direktori trash, maka file atau direktori tersebut akan dihapus permanen

**Jawab**

[Jawab Disini]

### Problem 1c
File atau direktori yang berada pada direktori trash tidak dapat diubah permission dan kepemilikannya, serta tidak dapat direname

**Jawab**

[Jawab Disini]

### Problem 1d
Untuk memulihkan file atau direktori dari direktori trash, anda harus menggunakan perintah mv dengan format mv [path_file_dalam_trash] [arg]. Opsi pertama untuk arg adalah dengan path biasa sehingga file atau direktori akan dipindahkan dari direktori trash ke path tersebut. Opsi kedua untuk arg adalah restore sehingga file atau direktori akan kembali ke path asal sebelum ia dipindah ke trash. Permission untuk file atau direktori yang dipulihkan harus kembali seperti sebelum dimasukkan ke trash. Khusus untuk arg restore anda harus membuat path yang sesuai apabila path asal tidak ada (terhapus/dipindah)

**Jawab**

[Jawab Disini]

### Problem 1e
Direktori trash tidak dapat dihapus, dipindah, direname. Anda juga tidak dapat membuat direktori dengan nama trash atau restore

**Jawab**

[Jawab Disini]

### Problem 1f
Catatlah log pada file trash.log. Format untuk tiap baris log adalah YYMMDD-HH:MM:SS KETERANGAN. Format keterangan akan berdasarkan aksi sesuai soal 1f

**Jawab**

[Jawab Disini]

### Kendala

[Tulis Disini]

## 2️⃣ Soal 2
### Problem 2a
Clone direktori target dan buatlah 4 user pada linux dengan username sesuai isi folder pada direktori target (password dibebaskan)

**Jawab**

[Jawab Disini]

### Problem 2b
Ketika folder mount point dari fuse yang kalian buat diakses, akan langsung menuju ke dalam target folder yang telah di clone (tidak dimulai dari root)

**Jawab**

[Jawab Disini]

### Problem 2c
Buatlah agar tiap user tidak dapat menambah, mengubah, maupun menghapus folder maupun file dalam folder yang bukan miliknya

**Jawab**

[Jawab Disini]

### Problem 2d
Buatlah agar user dapat menambah, mengubah, maupun menghapus folder maupun file dalam folder miliknya

**Jawab**

[Jawab Disini]

### Problem 2e
Semua isi file akan ter-encode jika diakses oleh selain user pemilik folder tersebut (menggunakan encoding Base64)

**Jawab**

[Jawab Disini]

### Problem 2f
Sebaliknya, file akan ter-decode ketika diakses oleh user pemilik folder tersebut

**Jawab**

[Jawab Disini]

### Kendala

[Tulis Disini]

## 3️⃣ Soal 3
### Problem 3a
Implementasikan fungsi `printString` pada `kernel.c` yang akan menampilkan string ke layar.

Implementasi dapat menggunakan fungsi `interrupt` dengan service `int 10h` dengan parameter `AH = 0x0E` untuk teletype output. Karakter yang ditampilkan dapat dimasukkan pada register `AL`. Fungsi ini akan menampilkan string karakter ASCII (null-terminated) ke layar

**Jawab**

*1. Persiapan environment untuk bochs di WSL*

Sebelumnya, hapus paket-paket perangkat lunak `bochs`, `bximage`, dan `bochsbios` dari sistem Linux.
```bash
sudo apt remove bochs bximage bochsbios
```
Setelah itu, install `alien` (untuk mengkonversi paket-paket perangkat lunak antara format paket yang berbeda) dan `rpm`
```bash
sudo apt install alien rpm
```
Setelah menginstall `alien` dan `rpm`, selanjutnya melakukan download bochs dengan ekstensi file `.rpm`. Bochs bisa didownload pada link [ini] (https://sourceforge.net/projects/bochs/files/bochs/2.8/). Pastikan Anda mendownload bochs yang bernama `bochs-2.8-1.x86_64.rpm`

Setelah download file selesai, pindahkan file tersebut ke tempat yang bisa diakses oleh terminal Linux/WSL/Ubuntu Anda. Anda bisa membuat directory `bochs` untuk menyimpan file `bochs-2.8-1.x86_64.rpm` tersebut. Jika sudah, install paket `.rpm` tersebut pada sistem Linux.
```bash
sudo alien -i bochs-2.8-1.x86_64.rpm
```
*2. Install `NASM`, `BCC`, `ld86`, dan `make`*
```bash
sudo apt install nasm
```
```bash
sudo apt install bcc
```
```bash
sudo apt install bin86
```
```bash
sudo apt install make
```
*3. Install library `SDL2`. `SDL2` adalah library multimedia yang banyak digunakan dalam pengembangan aplikasi yang memerlukan akses ke hardware tingkat rendah. Fungsinya untuk menyediakan serangkaian fungsi yang memungkinkan pengembang untuk mengakses perangkat keras seperti grafis, suara, input, dan lainnya dengan cara yang mudah dan platform-independen*
```bash
sudo apt install libsdl2-2.0-0
```

*4. Install library `libsamplerate`. Fungsi dari library tersebut untuk menyediakan alat yang efisien dan berkualitas tinggi untuk mengubah laju sampel (sampling rate) dari sinyal audio*
```bash
sudo apt install libsamplerate0
```

*5. Selanjutnya, membuat program fungsi `printString` pada `kernel.c`*
```C
void printString(char* str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '\n') {
            // Jika karakter newline ditemukan, tambahkan carriage return dan newline
            interrupt(0x10, 0x0E << 8 | '\r', 0, 0, 0);
            interrupt(0x10, 0x0E << 8 | '\n', 0, 0, 0);
        } else {
            // Menampilkan karakter yang dibaca
            interrupt(0x10, 0x0E << 8 | str[i], 0, 0, 0);
        }
        i++;
    }
}
```
- Fungsi tersebut menerima satu parameter yaitu pointer `char` yang menunjuk ke string yang akan ditampilkan
- `int i = 0` digunakan sebagai penghitung indeks untuk mengakses setiap karakter dalam string
- Loop `while` akan terus berjalan  selama karakter yang diakses pada indeks `i` bukan merupakan null terminator (`\0`). Null terminator menandakan akhir dari string C
- `if (str[i] == '\n')` digunakan untuk mengecek apakah karakter yang dibaca adalah newline (`\n`). Jika iya, dua interrupt BIOS dipanggil untuk menambahkan carriage return (`\r`) dan newline (`\n`) ke layar yang berguna untuk memastikan bahwa posisi kursor pindah ke awal baris berikutnya. Jika tidak, karakter tersebut akan ditampilkan pada layar
- `0x10` merupakan interrupt BIOS yang digunakan untuk layanan video/display
- `0x0E` digunakan untuk menampilkan karakter pada mode teks dengan menampilkan karakter pada posisi kursor saat ini dan menggerakkan kursor ke posisi berikutnya
- `<< 8` digunakan untuk  menggeser nilai `0x0E` ke kiri sebanyak 8 bit, sehingga nilai tersebut ditempatkan pada byte yang lebih tinggi dalam register yang digunakan untuk parameter interrupt BIOS

### Problem 3b
Implementasikan fungsi `readString` pada `kernel.c` yang akan membaca string dari keyboard.

Implementasi dapat menggunakan fungsi `interrupt` dengan service `int 16h` dengan parameter `AH = 0x00` untuk keyboard input. Fungsi ini akan membaca karakter ASCII (non-control) yang dimasukkan oleh pengguna dan menyimpannya pada buffer hingga menekan tombol `Enter`. Handle tombol `Backspace` dibebaskan kepada praktikan

**Jawab**

```C
void readString(char* buf) {
    int i = 0;
    char input;
    char capsLock = 0; // Variabel untuk menandai status Caps Lock

    while (1) {
        input = interrupt(0x16, 0, 0, 0, 0); // Baca karakter dari keyboard

        // Periksa apakah Caps Lock ditekan
        if (input == 0x3A) {
            capsLock = !capsLock; // Toggle status Caps Lock
            continue; // Lanjutkan ke iterasi berikutnya
        }

        // Jika Caps Lock aktif, ubah huruf menjadi huruf kapital
        if (capsLock && input >= 'a' && input <= 'z') {
            input -= 32; // Ubah ke huruf kapital
        }

        if (input == '\r') { // Jika tombol Enter ditekan
            buf[i] = '\0'; // Menambahkan null-terminator pada akhir string
            // Tambahkan carriage return dan newline
            interrupt(0x10, 0x0E << 8 | '\r', 0, 0, 0);
            interrupt(0x10, 0x0E << 8 | '\n', 0, 0, 0);
            break; // Keluar dari loop
        } else if (input == '\b') { // Jika tombol Backspace ditekan
            if (i > 0) { // Pastikan ada karakter untuk dihapus
                i--; // Pindah ke indeks sebelumnya
                // Hapus karakter dari layar dengan mencetak spasi dan kembali
                interrupt(0x10, 0x0E << 8 | '\b', 0, 0, 0);
                interrupt(0x10, 0x0E << 8 | ' ', 0, 0, 0);
                interrupt(0x10, 0x0E << 8 | '\b', 0, 0, 0);
            }
        } else if (input >= ' ' && input <= '~') { // Karakter ASCII yang valid
            buf[i] = input; // Menyimpan karakter pada buffer
            interrupt(0x10, 0x0E << 8 | input, 0, 0, 0); // Menampilkan karakter yang dibaca
            i++; // Pindah ke indeks berikutnya
        }
    }
}
```
- Fungsi tersebut menerima satu parameter yaitu pointer `char` yang menunjuk ke buffer tempat string akan disimpan
- `int i = 0` digunakan sebagai penghitung indeks untuk mengakses setiap posisi dalam buffer
- `char input` digunakan untuk menyimpan karakter yang dibaca dari keyboard
- `char capsLock = 0` digunakan untuk menandai status Caps Lock (aktif atau tidak)
- Loop `while (1)` akan selalu berjalan sampai pengguna menekan tombol enter
- `input = interrupt(0x16, 0, 0, 0, 0)` merupakan pemanggilan interrupt BIOS untuk membaca karakter dari keyboard
- `if (input == 0x3A)` digunakan untuk mengecek apakah Caps Lock ditekan. Jika iya, status Caps Lock di-toggle (diubah dari aktif menjadi tidak aktif atau sebaliknya)
- `if (capsLock && input >= 'a' && input <= 'z')` digunakan untuk mengecek apakah kondisi `capsLock` aktif dan karakter yang dibaca adalah huruf kecil. Jika iya,  karakter tersebut diubah menjadi huruf kapital dengan mengurangi nilai ASCII sebesar 32 (`input -= 32`)
- `if (input == '\r')` digunakan untuk mengecek apakah tombol Enter ditekan. Jika iya, null-terminator (`\0`) ditambahkan pada akhir string dalam buffer serta carriage return (`\r`) dan newline (`\n`) ditambahkan ke layar menggunakan interrupt BIOS untuk mengakhiri baris input
- `else if (input == '\b')`digunakan untuk mengecek apakah tombol Backspace ditekan. Jika iya, karakter akan dihapus dari layar dengan mencetak spasi di posisi kursor saat ini dan menggerakkan kursor kembali ke posisi sebelumnya
- `else if (input >= ' ' && input <= '~')` digunakan untuk mengecek apakah karakter yang dibaca valid. Jika iya, karakter tersebut disimpan dalam buffer dan ditampilkan pada layar dan indek `i` increment untuk menyimpan karakter berikutnya

### Problem 3c
Implementasikan fungsi `clearScreen` pada `kernel.c` yang akan membersihkan layar.

Ukuran layar adalah `80x25` karakter. Setelah layar dibersihkan, kursor akan kembali ke posisi awal yaitu `(0, 0)` dan buffer video untuk warna karakter diubah ke warna putih. Implementasi dapat menggunakan fungsi `interrupt` dengan service `int 10h` atau menggunakan fungsi `putInMemory` untuk mengisi memori video

**Jawab**

```C
void clearScreen() {
    int i;

    // Membersihkan layar dengan mengisi setiap karakter dengan spasi
    for (i = 0; i < 80 * 25; i++) {
        putInMemory(0xB800, i * 2, ' '); // Set karakter ke spasi
        putInMemory(0xB800, i * 2 + 1, 0x07); // Atur warna karakter ke putih
    }

    // Set kursor ke posisi awal (0, 0)
    interrupt(0x10, 0x02 << 8, 0, 0, 0);
}
```
- `int i` merupakan variabel `i` yang digunakan sebagai penghitung untuk iterasi melalui setiap karakter pada layar
- Dalam loop `for (i = 0; i < 80 * 25; i++)`, setiap karakter pada layar diisi dengan spasi
- `putInMemory` digunakan untuk menempatkan karakter spasi ke lokasi memori video VGA yang sesuai
- `0xB800` merupakan alamat memori VGA
- `i * 2` merupakan offset untuk karakter. Karakter ditempatkan pada setiap offset genap karena setiap karakter dalam mode teks diikuti oleh byte atribut warna di lokasi offset ganjil
- `i * 2 + 1` merupakan offset untuk karakter ganjil. Dalam kasus ini digunakan untuk mengatur atribut warna menjadi putih
- `0x07` digunakan untuk mewakili warna putih pada layar VGA dalam mode teks
- `0x02 << 8` digunakan untuk menunjukkan fungsi interrupt BIOS untuk mengatur posisi kursor

### Problem 3d
Lengkapi implementasi fungsi yang terdapat pada `std_lib.h` pada `std_lib.c`.

Fungsi-fungsi di atas dapat digunakan untuk mempermudah implementasi fungsi `printString`, `readString`, dan `clearScreen`

**Jawab**

```C
#include "std_lib.h"

int div(int a, int b) {
    // div untuk OS yang tidak memiliki fungsi pembagian
    int quotient = 0;
    while (a >= b) {
        a -= b;
        quotient++;
    }
    return quotient;
}

int mod(int a, int b) {
    // mod untuk OS yang tidak memiliki fungsi modulus
    while (a >= b) {
        a -= b;
    }
    return a;
}

void memcpy(byte* src, byte* dst, unsigned int size) {
    unsigned int i;
    for (i = 0; i < size; i++) {
        dst[i] = src[i];
    }
}

unsigned int strlen(char* str) {
    unsigned int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

bool strcmp(char* str1, char* str2) {
    unsigned int i = 0;
    while (str1[i] != '\0' || str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return false;
        }
        i++;
    }
    return true;
}

void strcpy(char* src, char* dst) {
    unsigned int i = 0;
    while (src[i] != '\0') {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
}

void clear(byte* buf, unsigned int size) {
    unsigned int i;
    for (i = 0; i < size; i++) {
        buf[i] = 0;
    }
}
```
- `int div(int a, int b)` digunakan untuk melakukan pembagian dua bilangan bulat
- `int mod(int a, int b)` digunakan untuk mendapatkan sisa dari pembagian dua bilangan bulat
- `void memcpy(byte* src, byte* dst, unsigned int size)` digunakan untuk menyalin data dari area memori yang ditunjuk oleh `src` ke area memori yang ditunjuk oleh `dst`. Parameter `size` menunjukkan jumlah byte yang akan disalin
- `unsigned int strlen(char* str)` digunakan untuk menghitung panjang dari string `str` dengan mengiterasi melalui karakter-karakternya hingga menemui karakter null terminator (`\0`) dan mengembalikannya (abaikan null terminator)
- `bool strcmp(char* str1, char* str2)` digunakan untuk membandingkan dua string `str1` dan `str2` karakter per karakter hingga menemui karakter null terminator pada salah satu dari kedua string tersebut. Jika kedua string identik, fungsi ini mengembalikan `true`, jika tidak, fungsi ini mengembalikan `false`
- `void strcpy(char* src, char* dst)` digunakan untuk menyalin string dari `src` ke `dst` termasuk null terminator
- `void clear(byte* buf, unsigned int size)` digunakan untuk mengisi area memori yang ditunjuk oleh `buf` dengan nilai 0. Parameter `size` menunjukkan jumlah byte yang akan diisi dengan nilai 0

### Problem 3e
Buat automasi untuk melakukan kompilasi dengan melengkapi file `makefile`.

Untuk melakukan kompilasi program, akan digunakan perintah `make build`. Semua hasil kompilasi program akan disimpan pada direktori `bin/`. Untuk menjalankan program, akan digunakan perintah `make run`.

**Jawab**

*1. Persiapan `makefile`*
```makefile
prepare:
	mkdir -p bin
	dd if=/dev/zero of=bin/floppy.img bs=512 count=2880

bootloader: 
	nasm -f bin src/bootloader.asm -o bin/bootloader.bin
	dd if=bin/bootloader.bin of=bin/floppy.img bs=512 count=1 conv=notrunc

stdlib:
	bcc -ansi -c -I./include src/std_lib.c -o bin/std_lib.o

kernel: 
	nasm -f as86 src/kernel.asm -o bin/kernel_asm.o
	bcc -ansi -c -I./include src/kernel.c -o bin/kernel.o

link:
	ld86 -o bin/kernel -d bin/kernel.o bin/kernel_asm.o bin/std_lib.o
	dd if=bin/kernel of=bin/floppy.img bs=512 seek=1 conv=notrunc

build: prepare bootloader stdlib kernel link

run:
	bochs -f bochsrc.txt 

clean:
	rm -f bin/*.o bin/*.bin bin/*.img

.PHONY: prepare bootloader stdlib kernel link build run clean
```
- `prepare` digunakan untuk membuat direktori `bin` jika belum ada, dan membuat file image disk kosong (`floppy.img`) dengan ukuran 2880 blok, masing-masing berukuran 512 byte
- `boatloader` digunakan untuk mengkompilasi bootloader dari file assembler `bootloader.asm` menjadi `bootloader.bin`. Kemudian, menggunakan `dd`, `bootloader.bin` disalin ke `floppy.img` pada blok pertama (blok boot) tanpa menghapus isi file image sebelumnya
- `stdlib` digunakan untuk mengkompilasi file C `std_lib.c` menjadi objek `std_lib.o` menggunakan compiler `bcc`. Argumen `-ansi` digunakan untuk mengompilasi sesuai dengan standar ANSI, dan `-I./include` digunakan untuk menyertakan direktori include yang diperlukan
- `kernel` digunakan untuk engkompilasi kernel dari file assembler `kernel.asm` dan file C `kernel.c` menjadi objek `kernel_asm.o` dan `kernel.o` menggunakan assembler `as86` dan compiler `bcc`
- `link` digunakan untuk menggabungkan objek `kernel_asm.o`, `kernel.o`, dan `std_lib.o` menjadi sebuah binary kernel bernama `kernel` menggunakan linker `ld86`. Binary kernel kemudian disalin ke `floppy.img` pada blok kedua menggunakan `dd`
- `build` merupakan target utama yang memanggil secara berurutan target-target `prepare`, `bootloader`, `stdlib`, `kernel`, dan `link` untuk membangun seluruh proyek kernel
- `run` digunakan untuk menjalankan emulator Bochs dengan menggunakan konfigurasi yang disimpan dalam file `bochsrc.txt`
- `clean` digunakan untuk menghapus semua file objek, file binary, dan file image yang dibuat selama proses kompilas
- `.PHONY` digunakan untuk membuat semua target yang terdaftar di atas dianggap sebagai target phony, yang berarti target tersebut tidak mewakili file yang sebenarnya. Ini penting agar `make` tidak memeriksa apakah ada file dengan nama yang sama dengan target sebelum menjalankan perintah

*2. Dokumentasi*
- Make build
![alt text](/resource/3e-1.png)
- Make run
![alt text](/resource/3e-2.png)
- Tampilan GUI, clearScreen, readString, dan printString
![alt text](/resource/3e-3.png)
- Before Delete
![alt text](/resource/3e-4.png)
- After Delete
![alt text](/resource/3e-15.png)

### Kendala

[Jawab Disini]

<div align=center>

# ------- SELESAI -------

</div>