#pragma once
#include <conio.h>

#include "Dot.h"
#include "DotMoving.h"

class Keyboard {
 public:
  Keyboard();
  ~Keyboard();
  void input(Dot& dot);
  void input(DotMoving& dotm);

 private:
};
