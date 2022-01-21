#include <string.h>
#include "Printer.h"
#include "Keyboard.h"

#pragma once
class Snake {
  friend class Printer;

 public:
  Snake(int size = 5);
  ~Snake(void);

  void up_direction(void);
  void down_direction(void);
  void left_direction(void);
  void right_direction(void);
  
  void unchange_direction(void);
  void refresh_coordinate(void);
  
  void set_direction(Keyboard::key & key);

  void write(Printer &);

 private:

  struct coordinate {
    int row;
    int column;
  };
  coordinate body[100];
  enum class direction { 
    left, 
    right, 
    up, 
    down 
  } direction;
};
