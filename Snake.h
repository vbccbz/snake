#include <string.h>
#pragma once
class Snake {
  friend class Printer;
 public:
  Snake(void);
  ~Snake(void);

  void up_direction(void);
  void down_direction(void);
  void left_direction(void);
  void right_direction(void);
  void unchange_direction(void);

  void refresh_coordinate(void);
  void resize(void);
  
  struct coordinate {
    int row;
    int column;
  };

 private:
  Snake::coordinate body[100];
  enum class direction { 
    left, 
    right, 
    up, 
    down 
  } direction;
  
};
