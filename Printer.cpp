#include "Printer.h"

Printer::Printer(void) {
  memset(buffer, '.', 100);
  tick = 0;
}
Printer::~Printer(void) { ; }

void Printer::print(void) {
#ifdef DEBUG
  std::cout << "tick " << tick << '\n';
  tick += 1;
#endif

  //std::cout << "Score: " << '\n'; 

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

  return;
}
