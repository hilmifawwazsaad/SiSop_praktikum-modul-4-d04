#include "kernel.h"
#include "std_lib.h"

void printString(char* str) {
    int i = 0;
    while (str[i] != '\0') {
        interrupt(0x10, 0x0E << 8 | str[i], 0, 0, 0);
        i++;
    }
}

void readString(char* buf) {
    int i = 0;
    char input;

    while (1) {
        input = interrupt(0x16, 0, 0, 0, 0); // Baca karakter dari keyboard
        if (input == '\r') { // Jika tombol Enter ditekan
            buf[i] = '\0'; // Menambahkan null-terminator pada akhir string
            break; // Keluar dari loop
        } else if (input >= ' ' && input <= '~') { // Karakter ASCII yang valid
            buf[i] = input; // Menyimpan karakter pada buffer
            interrupt(0x10, 0x0E << 8 | input, 0, 0, 0); // Menampilkan karakter yang dibaca
            i++; // Pindah ke indeks berikutnya
        }
    }
}

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

int main() {
  char buf[128];
  clearScreen();
  printString("Welcome to MengOS\n");

  while (true) {
    printString("$ ");
    readString(buf);
    printString(buf);
    printString("\n");
  }
}
