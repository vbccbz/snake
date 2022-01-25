#include "Snake.h"

Snake::Snake(void) {
  for (size_t element = 0; element < 100; element++) {
    body[element].position.row = -1;
    body[element].position.column = -1;
  }

  body[0].position.row = 5;
  body[0].position.column = 5;
  body[1].position.row = 5;
  body[1].position.column = 6;

  direction = direction::right;
};
Snake::~Snake(void) {}

void Snake::set_direction(Keyboard::keys& key, Printer& printer) {
  switch (key) {
    case Keyboard::keys::up:
      up_direction(printer);
      direction = direction::up;
      break;
    case Keyboard::keys::down:
      down_direction(printer);
      direction = direction::down;
      break;
    case Keyboard::keys::left:
      left_direction(printer);
      direction = direction::left;
      break;
    case Keyboard::keys::right:
      right_direction(printer);
      direction = direction::right;
      break;
    case Keyboard::keys::any:
      unchange_direction(printer);
      break;
    case Keyboard::keys::none:
      unchange_direction(printer);
      break;
    default:
      break;
  }
  return;
}
void Snake::up_direction(Printer& printer) {
  refresh_coordinates(printer);
  body[0].position.row -= 1;
  if (body[0].position.row < 0) {
    body[0].position.row = 9;
  }
  return;
}
void Snake::down_direction(Printer& printer) {
  refresh_coordinates(printer);
  body[0].position.row += 1;
  if (body[0].position.row > 9) {
    body[0].position.row = 0;
  }

  return;
}
void Snake::left_direction(Printer& printer) {
  refresh_coordinates(printer);
  body[0].position.column -= 1;
  if (body[0].position.column < 0) {
    body[0].position.column = 9;
  }
  return;
}
void Snake::right_direction(Printer& printer) {
  element temp = body[0];
  temp.position.column += 1;
  if (temp.position.column > 9) {
    temp.position.column = 0;
  }
  if (printer.buffer[temp.position.row * 10 + temp.position.column] == '-') {
    refresh_coordinates(printer);
    body[0] = temp;
  } else {
    
  }
  return;
}
void Snake::unchange_direction(Printer& printer) {
  switch (direction) {
    case direction::up:
      up_direction(printer);
      break;
    case direction::down:
      down_direction(printer);
      break;
    case direction::left:
      left_direction(printer);
      break;
    case direction::right:
      right_direction(printer);
      break;
    default:
      break;
  }
  return;
}

void Snake::refresh_coordinates(Printer& printer) {
  element temp, swap;
  temp = body[0];
  for (size_t element = 0; body[element].position.column != -1; element++) {
    swap = body[element];
    body[element] = temp;
    temp = swap;
  }
  return;
}

void Snake::write(Printer& printer) {
  for (size_t element = 0; body[element].position.row != -1; ++element) {
    int position =
        body[element].position.row * 10 + body[element].position.column;
    printer.buffer[position] = 'X';
  }
  return;
}
