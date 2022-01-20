#include "Dot.h"
#include "DotMoving.h"

#pragma once

class Printer {
 public:
  Printer(void);
  ~Printer(void);

  void print(void);

  void write(Dot&);
  void write(DotMoving&);
  

  char buffer[100];
  
 private:
  // char buffer[100]; ??????????????????????????? Что лучше? private и get_buffer или public ?

  //struct Pixel { int row, int column} pixels[100]; ????????
};