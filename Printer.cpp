#include "Printer.h"

Printer::Printer(void) {
  memset(buffer, '-', 100);
  frame = 0;
}
Printer::~Printer(void) { ; }

void Printer::print(void) {
#ifdef DEBUG
  std::cout << "frame " << frame << '\n';
  frame += 1;
#endif

  std::cout << "Score: " << score << '\n'; 

  for (size_t row = 0; row < 10; ++row) {
    for (size_t column = 0; column < 10; ++column) {
      std::cout << buffer[row * 10 + column];
    };
    std::cout << '\n';
  }

#ifdef DEBUG
  Sleep(1000);
#endif
#ifndef DEBUG
  Sleep(200);
  system("cls");
#endif

  memset(buffer, '-', 100);
  return;
}
