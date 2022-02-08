#include <string.h>

#include "Fruit.h"
#include "Keyboard.h"
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
  Snake(void);
  ~Snake(void);

  void move(Keyboard::keys &key, Printer &printer, Fruit& fruit);
  
  void write(Printer &);

 private:
  void update(void);
};
