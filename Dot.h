#pragma once
class Dot {
 public:
  Dot(int c1 = 5, int c2 = 5);
  ~Dot(void);
  //friend class Keyboard;
  friend class Printer;
  // int get_column(void);
  // int get_row(void);
  void print_coordinate(void);
  void up(void);
  void down(void);
  void left(void);
  void right(void);
 private:
  int column;
  int row;
};