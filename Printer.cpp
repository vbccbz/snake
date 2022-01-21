#include "Printer.h"

Printer::Printer(void) { memset(buffer, '-', 100); }
Printer::~Printer(void) { ; }

void Printer::print(void) {
  for (size_t row = 0; row < 10; ++row) {
    for (size_t column = 0; column < 10; ++column) {
      std::cout << buffer[row * 10 + column];
      // Sleep(10);
    };
    std::cout << '\n';
    // Sleep(10);
  }
  Sleep(500);
  system("cls");
  return;
}
