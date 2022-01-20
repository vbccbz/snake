#include "Keyboard.h"

Keyboard::Keyboard(void) { 
  code = key::none; 
}

Keyboard::~Keyboard(void) {}

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

void Keyboard::input(DotMoving& dotm) {
  if (_kbhit()) {
    switch (_getch()) {
      case 'w':
        dotm.up_direction();
        break;
      case 's':
        dotm.down_direction();
        break;
      case 'a':
        dotm.left_direction();
        break;
      case 'd':
        dotm.right_direction();
        break;
      default:
        dotm.unchange_direction();
        break;
    }
  } else {
    dotm.unchange_direction();
  }
}

Keyboard::key Keyboard::input(void) {  ////////////?
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
      default:
        code = key::any;
        break;
    }
  } else {
    code = key::none;
  }
  return code;
}
