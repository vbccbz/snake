#include "Fruit.h"

Fruit::Fruit(World& world) {
  // srand(time(NULL));
  //body.position.column = rand() % 10;
  //body.position.row = rand() % 10;

  body.position.row = 4;
  body.position.column = 5;
  world.table[body.position.row * 10 + body.position.column] = '$';
}

Fruit::~Fruit(void) {}

void Fruit::generate(World & world) {
  // srand(time(NULL));

  // в данном стиле если фрукт появится на столе под змейкой, то змейка затрёт его своими элементами и на следующем цикле условие сгенерирует новый фрукт
  // поэтому лучше заранее этот случай заблокировать
  if (world.table[body.position.row * 10 + body.position.column] != '$') {
    while (world.table[body.position.row * 10 + body.position.column] == 's' ||
           world.table[body.position.row * 10 + body.position.column] == 'S') {
      body.position.column = rand() % 10;
      body.position.row = rand() % 10;
    }
    world.table[body.position.row * 10 + body.position.column] = '$';
  }

  return;
}