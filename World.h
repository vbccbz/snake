#include "Keyboard.h"
#include "Snake.h"

#pragma once

class World {
 private:
  Keyboard keyboard;

 public:
  World();
  ~World();
  void logic(Snake& snake);
};
