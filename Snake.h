#include <string.h>

#include "Keyboard.h"
#include "Printer.h"

#pragma once
class Snake {
  friend class Printer;

 public:
  Snake(void);
  ~Snake(void);

  void set_direction(Keyboard::keys &key, Printer &printer);

  void refresh_coordinates(Printer &printer);

  void up_direction(Printer &printer);
  void down_direction(Printer &printer);
  void left_direction(Printer &printer);
  void right_direction(Printer &printer);

  void unchange_direction(Printer &printer);

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
};
