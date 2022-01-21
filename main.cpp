#include "Snake.h"
#include "World.h"
#include "Printer.h"

int main(void) {
  Snake snake ;
  Printer printer;
  World world;

  snake.write(printer);
  printer.print();

  while (1) {
    world.logic(snake);
    snake.write(printer);
    printer.print();
  }
  return 0;
}
