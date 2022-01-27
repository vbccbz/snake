#include <string.h>

#include "Fruit.h"
#include "Keyboard.h"
#include "Printer.h"

#pragma once
class Snake {
  friend class Printer;

 public:
  Snake(void);
  ~Snake(void);

  void set_direction(Keyboard::keys &key, Printer &printer, Fruit &fruit);

  void refresh_coordinates(void);

  void up_direction(Printer &printer, Fruit &fruit);
  void down_direction(Printer &printer, Fruit &fruit);
  void left_direction(Printer &printer, Fruit &fruit);
  void right_direction(Printer &printer, Fruit &fruit);

  void unchange_direction(Printer &printer, Fruit &fruit);


  void write(Printer &);

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
  void add_coordinates(Printer &printer, Fruit &fruit, Snake::element &temp);
};
