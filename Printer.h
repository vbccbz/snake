#include "Dot.h"
#pragma once

class Printer {
 public:
  Printer(void);
  ~Printer(void);
  void write(Dot& dot);
  void print(void);

 private:
  char arr[100];
};