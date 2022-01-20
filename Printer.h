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
  // char buffer[100]; ??????????????????????????? ��� �����? private � get_buffer ��� public ?

  //struct Pixel { int row, int column} pixels[100]; ????????
};