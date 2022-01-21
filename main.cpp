#include "Keyboard.h"
#include "Snake.h"
#include "Fruit.h"
#include "Printer.h"
#include "World.h"

int main(void) {
  Keyboard keyboard;
  Snake snake;
  Fruit fruit;
  Printer printer;
  World world;

  while (1) {
    keyboard.input();
    
    //fruit.generate();
    //fruit.write(printer);

    snake.set_direction(keyboard.code);
    snake.write(printer);
    

    printer.print();
  }
  return 0;
}
