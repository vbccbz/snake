#include "Snake.h"

Snake::Snake(int size) {
  for (size_t element = 0; element < 100; element++) {
    body[element].row = -1;
    body[element].column = -1;
  }
  
  int start_position = 5;
  for (size_t element = 0; element < size; element++) {
    body[element].row = 5;
    body[element].column = start_position;
    --start_position;
  }

  direction = direction::right;
};
Snake::~Snake(void) {}

void Snake::up_direction(void) {
  refresh_coordinate();

  body[0].row -= 1;
  if (body[0].row < 0) {
    body[0].row = 9;
  }

  direction = direction::up;
}
void Snake::down_direction(void) {
  refresh_coordinate();

  body[0].row += 1;
  if (body[0].row > 9) {
    body[0].row = 0;
  }

  direction = direction::down;
}
void Snake::left_direction(void) {
  refresh_coordinate();

  body[0].column -= 1;
  if (body[0].column < 0) {
    body[0].column = 9;
  }

  direction = direction::left;
}
void Snake::right_direction(void) {
  refresh_coordinate();

  body[0].column += 1;
  if (body[0].column > 9) {
    body[0].column = 0;
  }

  direction = direction::right;
}
void Snake::unchange_direction(void) {
  switch (direction) {
    case direction::up:
      up_direction();
      break;
    case direction::down:
      down_direction();
      break;
    case direction::left:
      left_direction();
      break;
    case direction::right:
      right_direction();
      break;
    default:
      break;
  }
  return;
}

void Snake::refresh_coordinate(void) {
  Snake::coordinate temp, swap;
  temp = body[0];
  for (size_t element = 0; body[element].column != -1; element++) {
    swap = body[element];
    body[element] = temp;
    temp = swap;
  }
  return;
}

void Snake::write(Printer & printer) {
    memset(printer.buffer, '-', 100);
    for (size_t element = 0; body[element].row != -1; ++element) {
      int position = body[element].row * 10 + body[element].column;
      printer.buffer[position] = 'X';
    }
  return;
}
