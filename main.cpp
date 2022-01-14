#include <conio.h>
#include <windows.h>
//#include <stdio.h>
#include <iostream>
#include <iomanip>
int main(void) {
  char c;
  while (1) {
    //  c = _getch();
    //  std::cout << (int)c << '\n';
    for (size_t i = 0; i < 25; i++) {
      //printf("%2d ", i);
      std::cout << std::setw(2) << i << ' ';
      for (size_t i = 0; i < 50; i++) {
        std::cout << "*";
      }
      std::cout << '\n';
    }
    Sleep(500);  // sleep(10);
    system("cls");
  }
  return 0;
}
