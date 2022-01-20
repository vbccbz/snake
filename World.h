#include "Keyboard.h"
#include "Dot.h"
#include "DotMoving.h"
#include "Snake.h"

#pragma once
class World {
 private:
  Keyboard keyboard;

 public:
  World();
  ~World();
  void logic(Dot& dot);
  void logic(DotMoving& dot);
  void logic(Snake& snake);
};
