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

  enum class key { left, right, up, down, any, none } code; //???????????????????? Why can't go after?
  Keyboard::key input(void);///////////????????
  
 private:

};
