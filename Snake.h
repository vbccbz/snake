#include <string.h>
#include "Printer.h"

#pragma once
class Snake {
  friend class Printer;

 public:
  Snake(int size = 2);
  ~Snake(void);

  void up_direction(void);
  void down_direction(void);
  void left_direction(void);
  void right_direction(void);
  void unchange_direction(void);

  void refresh_coordinate(void);
  
  void write(Printer &);

  struct coordinate {
    int row;
    int column;
  };

 private:
  coordinate body[100];
  enum class direction { 
    left, 
    right, 
    up, 
    down 
  } direction;
};
