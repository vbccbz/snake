//#define DEBUG

#include <iostream>
#include <string.h>
#include <windows.h>

#pragma once

class Printer {
 public:
  Printer(void);
  ~Printer(void);

  char buffer[100];

  //struct pixel {
  //  int row;
  //  int column;
  //};
  //pixel buffer2[100];

  void print(void);

 private:
  void clear(void);
  int frame;
  // char buffer[100]; ??????????????????????????? Что лучше? private и get_buffer или public ?
  //struct Pixel { int row, int column} buffer[100]; ????????
  enum class status {
    input,
    logic,
    draw,

  };
};