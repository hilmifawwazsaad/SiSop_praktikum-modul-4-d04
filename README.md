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

[Jawab Disini]

### Problem 3b
Implementasikan fungsi `readString` pada `kernel.c` yang akan membaca string dari keyboard.

Implementasi dapat menggunakan fungsi `interrupt` dengan service `int 16h` dengan parameter `AH = 0x00` untuk keyboard input. Fungsi ini akan membaca karakter ASCII (non-control) yang dimasukkan oleh pengguna dan menyimpannya pada buffer hingga menekan tombol `Enter`. Handle tombol `Backspace` dibebaskan kepada praktikan

**Jawab**

[Jawab Disini]

### Problem 3c
Implementasikan fungsi `clearScreen` pada `kernel.c` yang akan membersihkan layar.

Ukuran layar adalah `80x25` karakter. Setelah layar dibersihkan, kursor akan kembali ke posisi awal yaitu `(0, 0)` dan buffer video untuk warna karakter diubah ke warna putih. Implementasi dapat menggunakan fungsi `interrupt` dengan service `int 10h` atau menggunakan fungsi `putInMemory` untuk mengisi memori video

**Jawab**

[Jawab Disini]

### Problem 3d
Lengkapi implementasi fungsi yang terdapat pada `std_lib.h` pada `std_lib.c`.

Fungsi-fungsi di atas dapat digunakan untuk mempermudah implementasi fungsi `printString`, `readString`, dan `clearScreen`

**Jawab**

[Jawab Disini]

### Problem 3e
Buat automasi untuk melakukan kompilasi dengan melengkapi file `makefile`.

Untuk melakukan kompilasi program, akan digunakan perintah `make build`. Semua hasil kompilasi program akan disimpan pada direktori `bin/`. Untuk menjalankan program, akan digunakan perintah `make run`.

**Jawab**

[Jawab Disini]

### Kendala

[Jawab Disini]

<div align=center>

# ------- SELESAI -------

</div>