#include "Dot.h"
#include "Keyboard.h"
#include "DotMoving.h"

#pragma once
class World {
 public:
  World();
  ~World();
  void logic(Dot& dot);
  void logic(DotMoving & dot);

 private:
  Keyboard keyboard;
};
