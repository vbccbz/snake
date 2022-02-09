#include <string.h>

#include "Keyboard.h"
#include "World.h"
#include "Printer.h"
#include "Fruit.h"

#include <iostream>
#pragma once
class Snake {
  friend class Printer;

 private:

  struct element {
    struct coordinate {
      int row;
      int column;
    } position;
    int number;
  };
  element body[100];
  size_t length;
  enum class direction { left, right, up, down } direction;

 public:
  Snake(World & world);
  ~Snake(void);

  void move(Keyboard::keys &key, World &world);

 private:
  void update(void);
};
