#define DEBUG

#include <iostream>
#include <string.h>
#include <windows.h>

#pragma once

class Printer {
 private:
  int frame;

 public:
  Printer(void);
  ~Printer(void);
  char buffer[100];
  int score;
  void print(void);
};
