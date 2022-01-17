#include "Dot.h"
#include "DotMoving.h"

#pragma once

class Printer {
 public:
  Printer(void);
  ~Printer(void);
  void write(Dot& dot);
  void write(DotMoving& dotm);

  void print(void);

 private:
  char arr[100];
};