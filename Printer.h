#define DEBUG

#include <iostream>
#include <string.h>
#include <windows.h>

#pragma once

class Printer {
 private:
  int tick;

 public:
  Printer(void);
  ~Printer(void);
  char buffer[1000];
  void print(void);
};
