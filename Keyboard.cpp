#include "Keyboard.h"

Keyboard::Keyboard() {}

Keyboard::~Keyboard() {}

void Keyboard::input(Dot& dot) {
  if (_kbhit()) {
    switch (_getch()) {
      case 'w':
        dot.up();
        break;
      case 's':
        dot.down();
        break;
      case 'a':
        dot.left();
        break;
      case 'd':
        dot.right();
        break;
      default:
        break;
    }
  }
}
