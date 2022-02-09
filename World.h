#include "Printer.h"
#include <string.h>

#pragma once
class World {
 public:
  World();
  ~World();
  char table[100];
  void write(Printer& printer);
 private:
};

