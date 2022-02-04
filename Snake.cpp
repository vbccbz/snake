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

void Snake::set_direction(Keyboard::keys& key, Printer& printer, Fruit& fruit) {
  switch (key) {
    case Keyboard::keys::up:
      up_direction(printer, fruit);
      direction = direction::up;
      break;
    case Keyboard::keys::down:
      down_direction(printer, fruit);
      direction = direction::down;
      break;
    case Keyboard::keys::left:
      left_direction(printer, fruit);
      direction = direction::left;
      break;
    case Keyboard::keys::right:
      right_direction(printer, fruit);
      direction = direction::right;
      break;
    case Keyboard::keys::none:
      unchange_direction(printer, fruit);
      break;
    case Keyboard::keys::any:
      unchange_direction(printer, fruit);
      break;
  }
  return;
}
void Snake::up_direction(Printer& printer, Fruit& fruit) {
  element temp = body[0];
  temp.position.row -= 1;
  if (temp.position.row < 0) {
    temp.position.row = 9;
  }
  add_coordinates(printer, fruit, temp);
  return;
}
void Snake::down_direction(Printer& printer, Fruit& fruit) {
  element temp = body[0];
  temp.position.row += 1;
  if (temp.position.row > 9) {
    temp.position.row = 0;
  }
  add_coordinates(printer, fruit, temp);
  return;
}
void Snake::left_direction(Printer& printer, Fruit& fruit) {
  element temp = body[0];
  temp.position.column -= 1;
  if (temp.position.column < 0) {
    temp.position.column = 9;
  }
  add_coordinates(printer, fruit, temp);
  return;
}
void Snake::right_direction(Printer& printer, Fruit& fruit) {
  element temp = body[0];
  temp.position.column += 1;
  if (temp.position.column > 9) {
    temp.position.column = 0;
  }
  add_coordinates(printer, fruit, temp);
  return;
}
void Snake::unchange_direction(Printer& printer, Fruit& fruit) {
  switch (direction) {
    case direction::up:
      up_direction(printer, fruit);
      break;
    case direction::down:
      down_direction(printer,fruit);
      break;
    case direction::left:
      left_direction(printer, fruit);
      break;
    case direction::right:
      right_direction(printer, fruit);
      break;
    default:
      break;
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

void Snake::add_coordinates(Printer& printer, Fruit& fruit, element &temp ) {
  if (printer.buffer[temp.position.row * 10 + temp.position.column] == '-') {
    refresh_coordinates();
    body[0] = temp;
  }
  if (printer.buffer[temp.position.row * 10 + temp.position.column] == '$') {
    fruit.clear();
    length += 1;
    refresh_coordinates();
    body[0] = temp;
  }
}

void Snake::write(Printer& printer) {
  for (size_t element = 0; element != length; ++element) {
    printer.buffer[body[element].position.row * 10 +
                   body[element].position.column] = 'X';
  }
  return;
}
