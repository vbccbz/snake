#include "Snake.h"

Snake::Snake(void) {
  for (size_t element = 0; element < 100; element++) {
    body[element].position.row = -1;
    body[element].position.column = -1;
  }

  body[0].position.row = 6;
  body[0].position.column = 5;
  body[1].position.row = 6;
  body[1].position.column = 6;

  direction = direction::right;
  length = 2;
};

Snake::~Snake(void) {}

void Snake::up_direction(Snake::element& temp) {
  temp.position.row -= 1;
  if (temp.position.row < 0) {
    temp.position.row = 9;
  }
  return;
}

void Snake::down_direction(Snake::element& temp) {
  temp.position.row += 1;
  if (temp.position.row > 9) {
    temp.position.row = 0;
  }
  return;
}

void Snake::left_direction(Snake::element& temp) {
  temp.position.column -= 1;
  if (temp.position.column < 0) {
    temp.position.column = 9;
  }
  return;
}

void Snake::right_direction(Snake::element& temp) {
  temp.position.column += 1;
  if (temp.position.column > 9) {
    temp.position.column = 0;
  }
  return;
}

void Snake::refresh_coordinates(void) {
  element temp1, temp2;
  temp1 = body[0];
  for (size_t element = 1; element < length; element++) {
    temp2 = body[element];
    body[element] = temp1;
    temp1 = temp2;
  }
  return;
}

void Snake::write(Printer& printer) {
  for (size_t element = 0; element != length; ++element) {
    printer.buffer[body[element].position.row * 10 +
                   body[element].position.column] = 'X';
  }
  return;
}

void Snake::move(Keyboard::keys& key, Printer& printer, Fruit& fruit) {
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
      up_direction(temp);
      break;
    case direction::down:
      down_direction(temp);
      break;
    case direction::left:
      left_direction(temp);
      break;
    case direction::right:
      right_direction(temp);
      break;
    default:
      break;
  }
  if (printer.buffer[temp.position.row * 10 + temp.position.column] == '-') {
    refresh_coordinates();
    body[0] = temp;
  }
  if (printer.buffer[temp.position.row * 10 + temp.position.column] == '$') {
    length += 1;
    refresh_coordinates();
    body[0] = temp;

    fruit.generate();
    fruit.write(printer);
  }
  return;
}