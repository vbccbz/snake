#include "Snake.h"

Snake::Snake(void) {
  for (size_t element = 0; element < 100; element++) {
    body[element].row = -1;
    body[element].column = -1;
  }
  direction = direction::right;
  body[0].row = 5;
  body[1].row = 5;
  body[2].row = 5;
  body[3].row = 5;

  body[0].column = 0;
  body[1].column = 1;
  body[2].column = 2;
  body[3].column = 3;
};
Snake::~Snake(void) {}

void Snake::up_direction(void) {
  // int temp, swap;
  // temp = 0;
  // for (size_t element = 0; element < 5; element++) {
  //  swap = array[element];
  //  array[element] = temp;
  //  temp = swap;
  //}

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
}

void Snake::refresh_coordinate(void) {
  Snake::coordinate temp, swap;
  temp = body[0];
  for (size_t element = 0; body[element].column != -1; element++) {
    swap = body[element];
    body[element] = temp;
    temp = swap;
  }
}
void Snake::resize(void) {}