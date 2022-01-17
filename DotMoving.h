#pragma once
#pragma once
class DotMoving {
 public:
  DotMoving(int c1 = 5, int c2 = 5);
  ~DotMoving(void);
  
  friend class Printer;

  void print_coordinate(void);
  void up_direction(void);
  void down_direction(void);
  void left_direction(void);
  void right_direction(void);
  void unchange_direction(void);

 private:
  int column;
  int row;
  int direction;
};
