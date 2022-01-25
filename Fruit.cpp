#include "Fruit.h"

Fruit::Fruit(void) {
  body.position.column = 5;
  body.position.row = 5;
}

Fruit::~Fruit(void) {}

void Fruit::generate(void) {
  // srand(time(NULL));
  if (body.position.row == -1) {
    body.position.column = rand() % 10;
    body.position.row = rand() % 10;
  }
  return;
}

void Fruit::write(Printer& printer) {
  int position = body.position.row * 10 + body.position.column;
  printer.buffer[position] = '$';
  return;
}
