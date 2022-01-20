#include "DotMoving.h"

DotMoving::DotMoving(int c1, int c2) {
  column = c1;
  row = c2;
  direction = direction::right;
}
DotMoving::~DotMoving(void) { ; }

void DotMoving::print_coordinate(void) {
  std::cout << "DotMoving" << '\n';
  std::cout << "column = " << column << '\n';
  std::cout << "row = " << row << '\n';
}

void DotMoving::up_direction(void) {
  row -= 1;
  if (row < 0) {
    row = 9;
  }
  direction = direction::up;
}
void DotMoving::down_direction(void) {
  row += 1;
  if (row > 9) {
    row = 0;
  }
  direction = direction::down;
}
void DotMoving::left_direction(void) {
  column -= 1;
  if (column < 0) {
    column = 9;
  }
  direction = direction::left;
}
void DotMoving::right_direction(void) {
  column += 1;
  if (column > 9) {
    column = 0;
  }
  direction = direction::right;
}
void DotMoving::unchange_direction(void) {
  switch (direction) {
    case direction::up :
      up_direction();
      break;
    case direction::down :
      down_direction();
      break;
    case direction::left :
      left_direction();
      break;
    case direction::right :
      right_direction();
      break;
    default: 
      break;
  }
}
