#include "Keyboard.h"

Keyboard::Keyboard(void) { 
  code = key::none; 
}

Keyboard::~Keyboard(void) {}

void Keyboard::input(void) {  ////////////?
  if (_kbhit()) {
    switch (_getch()) {
      case 'w':
        code = key::up;
        break;
      case 's':
        code = key::down;
        break;
      case 'a':
        code = key::left;
        break;
      case 'd':
        code = key::right;
        break;
      case ';':
        code = key::esc;
        break;
      default:
        code = key::any;
        break;
    }
  } else {
    code = key::none;
  }
  return;
}
