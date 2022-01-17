#include <iostream>

#include "DotMoving.h"

DotMoving::DotMoving(int c1, int c2) {
  column = c1;
  row = c2;
  direction = 3;
}

DotMoving::~DotMoving(void) { ; }

// int DotMoving::get_column(void) { return column; }

// int DotMoving::get_row(void) { return row; }

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
  direction = 0;
}

void DotMoving::down_direction(void) {
  row += 1;
  if (row > 9) {
    row = 0;
  }
  direction = 1;
}

void DotMoving::left_direction(void) {
  column -= 1;
  if (column < 0) {
    column = 9;
  }
  direction = 2;
}

void DotMoving::right_direction(void) {
  column += 1;
  if (column > 9) {
    column = 0;
  }
  direction = 3;
}

void DotMoving::unchange_direction(void) {
  switch (direction) {
    case 0:
      up_direction();
      break;
    case 1:
      down_direction();
      break;
    case 2:
      left_direction();
      break;
    case 3:
      right_direction();
      break;
    default: 
      break;
  }
}
