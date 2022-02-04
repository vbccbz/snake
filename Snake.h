#include <string.h>

#include "Fruit.h"
#include "Keyboard.h"
#include "Printer.h"

#pragma once
class Snake {
  friend class Printer;

 private:
  struct coordinate {
    int row;
    int column;
  };
  struct element {
    coordinate position;
  };
  element body[100];
  enum class direction { left, right, up, down };
  direction direction;
  size_t length;

 public:
  Snake(void);
  ~Snake(void);

  void move(Keyboard::keys &key, Printer &printer, Fruit &fruit);
 
  void up_direction(Snake::element &temp);
  void down_direction(Snake::element &temp);
  void left_direction(Snake::element &temp);
  void right_direction(Snake::element &temp);
  
  void refresh_coordinates(void);
  
  void write(Printer &);
};
