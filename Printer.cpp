#include "Printer.h"

Printer::Printer(void) { memset(buffer, '-', 100); }
Printer::~Printer(void) { ; }

void Printer::print(void) {
  for (size_t row = 0; row < 10; ++row) {
    for (size_t column = 0; column < 10; ++column) {
      std::cout << buffer[row * 10 + column];
      // Sleep(50);
    };
    std::cout << '\n';
    // Sleep(50);
  }
  Sleep(100);
  system("cls");
  memset(buffer, '-', 100);

  return;
}

void Printer::clear(void) {
  //pixel zero;
  //zero.column = -1;
  //zero.row = -1;
  //for (size_t i = 0; i < 100; i++) {
  //  buffer2[i] = zero;
  //}
  return;
}