#include <iostream>
#include <iomanip>
#include <string.h>
#include <windows.h>

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
  Sleep(150);
  system("cls");
  return;
}

void Printer::write(Dot& dot) {
  memset(buffer, '-', 100);
  // buffer[dot.get_row() * 10 + dot.get_column()] = 'X';
  buffer[dot.row * 10 + dot.column] = 'X';
  return;
}
void Printer::write(DotMoving & dotm) {
  memset(buffer, '-', 100);
  buffer [dotm.row * 10 + dotm.column] = 'X';
  return;
}




