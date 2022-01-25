#include "Keyboard.h"

Keyboard::Keyboard(void) { key = keys::none; }

Keyboard::~Keyboard(void) {}

void Keyboard::input(void) {  ////////////?
  if (_kbhit()) {
    switch (_getch()) {
      case 'w':
        key = keys::up;
        break;
      case 's':
        key = keys::down;
        break;
      case 'a':
        key = keys::left;
        break;
      case 'd':
        key = keys::right;
        break;
      case 27: //case 'ESC':
        key = keys::esc;
        break;
      default:
        key = keys::any;
        break;
    }
  } else {
    key = keys::none;
  }
  return;
}
