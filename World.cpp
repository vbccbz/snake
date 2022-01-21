#include "World.h"

World::World() {}

World::~World() {}

void World::logic(Snake& snake) {
  switch (keyboard.input()) {
    case Keyboard::key::up:
      snake.up_direction();
      break;
    case Keyboard::key::down:
      snake.down_direction();
      break;
    case Keyboard::key::left:
      snake.left_direction();
      break;
    case Keyboard::key::right:
      snake.right_direction();
      break;
    case Keyboard::key::any:
      snake.unchange_direction();
      break;
    case Keyboard::key::none:
      snake.unchange_direction();
      break;

    case Keyboard::key::esc:
      
      break;

    default:
      break;
  }
  return;
}
