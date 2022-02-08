#include "Snake.h"

Snake::Snake(void) {
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
};

Snake::~Snake(void) {}

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

  // логика головы, логика хвоста
  // голова будет сталкиваться с элементом, который на самом деле вышел бы
  // из-под удара в следующем тике
  // логика хвоста, логика головы
  // лучше выход за границы реальной длина (length) не критичен, потому что все
  // остальные взаимодействия ограничены length

  // update all elements
  update();

  // choose direction for first element
  switch (direction) {
    case direction::up:
      body[0].position.row -= 1;
      if (body[0].position.row < 0) {
        body[0].position.row = 9;
      }
      break;
    case direction::down:
      body[0].position.row += 1;
      if (body[0].position.row > 9) {
        body[0].position.row = 0;
      }
      break;
    case direction::left:
      body[0].position.column -= 1;
      if (body[0].position.column < 0) {
        body[0].position.column = 9;
      }
      break;
    case direction::right:
      body[0].position.column += 1;
      if (body[0].position.column > 9) {
        body[0].position.column = 0;
      }
      break;
    default:
      break;
  }

  // find intersection
  for (size_t element = 1; element < length; element++) {
    if (body[0].position.row == body[element].position.row &&
        body[0].position.column == body[element].position.column) {
      length = body[element].number;
    }
  }

  // check fruit, eat fruit
  if (printer.buffer[body[0].position.row * 10 + body[0].position.column] ==
      '$') {
    length += 1;
    fruit.generate();
    fruit.write(printer);
  }

  return;
}
void Snake::update(void) {
  element temp1, temp2;
  temp1.position = body[0].position;
  for (size_t element = 0; element <= length; ++element) {  //!!!!!!!!
    temp2.position = body[element].position;
    body[element].position = temp1.position;
    temp1.position = temp2.position;
  }
}

void Snake::write(Printer& printer) {
  printer.buffer[body[0].position.row * 10 + body[0].position.column] = 'S';
  for (size_t element = 1; element < length; ++element) {
    int place = body[element].position.row * 10 + body[element].position.column;
    printer.buffer[place] = 's';
  }
  return;
}
