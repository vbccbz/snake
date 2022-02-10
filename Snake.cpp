#include "Snake.h"

Snake::Snake(World& world) {
  for (size_t element = 0; element < 100; element++) {
    body[element].position.row = -1;
    body[element].position.column = -1;
    body[element].number = element;
  }
  direction = direction::right;
  length = 5;

  body[0].number = 0;
  body[1].number = 1;
  body[2].number = 2;
  body[3].number = 3;
  body[4].number = 4;

  body[0].position.row = 5;
  body[1].position.row = 5;
  body[2].position.row = 5;
  body[3].position.row = 5;
  body[4].position.row = 5;

  body[0].position.column = 5;
  body[1].position.column = 4;
  body[2].position.column = 3;
  body[3].position.column = 2;
  body[4].position.column = 1;

  world.table[body[0].position.row * 10 + body[0].position.column] = 'S';
  for (size_t element = 1; element < length; element++) {
    world.table[body[element].position.row * 10 + body[element].position.column] = 's';
  }

  return;
};

Snake::~Snake(void) {}

void Snake::move(Keyboard::keys& key, World& world) {
  switch (key) {
    case Keyboard::keys::up:
      direction = direction::up;
      break;
    case Keyboard::keys::down:
      direction = direction::down;
      break;
    case Keyboard::keys::left:
      direction = direction::left;
      break;
    case Keyboard::keys::right:
      direction = direction::right;
      break;
    case Keyboard::keys::none:
      break;
    case Keyboard::keys::any:
      break;
  }

  element temp = body[0];

  switch (direction) {
    case direction::up:
      temp.position.row -= 1;
      if (temp.position.row < 0) {
        temp.position.row = 9;
      }
      break;
    case direction::down:
      temp.position.row += 1;
      if (temp.position.row > 9) {
        temp.position.row = 0;
      }
      break;
    case direction::left:
      temp.position.column -= 1;
      if (temp.position.column < 0) {
        temp.position.column = 9;
      }
      break;
    case direction::right:
      temp.position.column += 1;
      if (temp.position.column > 9) {
        temp.position.column = 0;
      }
      break;
    default:
      break;
  }

  switch (world.table[temp.position.row * 10 + temp.position.column]) {
    case '-':
      // clear
      world.table[body[length - 1].position.row * 10 +
                  body[length - 1].position.column] = '-';

      update();
      body[0].position = temp.position;

      world.table[body[0].position.row * 10 + body[0].position.column] = 'S';
      for (size_t element = 1; element < length; element++) {
        world.table[body[element].position.row * 10 +
                    body[element].position.column] = 's';
      }

      break;

    case '$':
      // no clear

      length += 1;
      update();
      body[0].position = temp.position;

      world.table[body[0].position.row * 10 + body[0].position.column] = 'S';
      for (size_t element = 1; element < length; element++) {
        world.table[body[element].position.row * 10 +
                    body[element].position.column] = 's';
      }

      break;

    case 's':
      // clear
      for (size_t element = 0; element < length; element++) {
        world.table[body[element].position.row * 10 +
                    body[element].position.column] = '-';
      }
  
      // find intersection
      for (size_t element = 1; element < length; element++) {
        if (temp.position.row == body[element].position.row &&
            temp.position.column == body[element].position.column) {
          length = body[element].number + 1;
        }
      }

      update();
      body[0].position = temp.position;

      world.table[body[0].position.row * 10 + body[0].position.column] = 'S';
      for (size_t element = 1; element < length; element++) {
        world.table[body[element].position.row * 10 +
                    body[element].position.column] = 's';
      }

      break;

    default:

      break;
  }

  return;
}

void Snake::update(void) {
  element temp1, temp2;
  temp1.position = body[0].position;
  for (size_t element = 1; element < length; ++element) {  
    temp2.position = body[element].position;
    body[element].position = temp1.position;
    temp1.position = temp2.position;
  }
}
