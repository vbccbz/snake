#include <iostream>
#include "Dot.h"

Dot::Dot(int c1, int c2) {
  column = c1;
  row = c2;
}

Dot::~Dot(void) { ; }

// int Dot::get_column(void) { return column; }

// int Dot::get_row(void) { return row; }

void Dot::print_coordinate(void) {
  std::cout << "dot" << '\n';
  std::cout << "column = " << column << '\n';
  std::cout << "row = " << row << '\n';
}

void Dot::up(void) {
  row -= 1;
  if (row < 0) {
    row = 9;
  }
}
void Dot::down(void) {
  row += 1;
  if (row > 9) {
    row = 0;
  }
}
void Dot::left(void) {
  column -= 1;
  if (column < 0) {
    column = 9;
  }
}
void Dot::right(void) {
  column += 1;
  if (column > 9) {
    column = 0;
  }
}