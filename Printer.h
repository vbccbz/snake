#include "Dot.h"
#include "DotMoving.h"
#include "Snake.h"

#pragma once

class Printer {
 public:
  Printer(void);
  ~Printer(void);

  void print(void);

  void write(Dot&);
  void write(DotMoving&);
  void write(Snake&);

 private:
  char buffer[100];
  //struct Pixel { int row, int column} pixels[100]; ????????
};