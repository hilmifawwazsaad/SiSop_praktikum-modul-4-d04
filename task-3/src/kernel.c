#include "kernel.h"
#include "std_lib.h"

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
