#include <stdlib.h>
#include <time.h>

#include "Printer.h"

#pragma once
class Fruit {
 public:
  Fruit(void);
  ~Fruit(void);
  void generate(void);
  void write(Printer & printer);
 private:
  struct element {
    struct coordinate {
      int row;
      int column;
    } position;
  } body;
};

