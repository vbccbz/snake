#include <stdlib.h>
#include <time.h>

#include "World.h"
#include "Printer.h"

#pragma once
class Fruit {
 public:
  Fruit(World& world);
  ~Fruit(void);
  void generate(void);
  void generate(World& world);
  void write(Printer & printer);
 private:
  struct element {
    struct coordinate {
      int row;
      int column;
    } position;
  } body;
};

