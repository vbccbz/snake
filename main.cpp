#include "Keyboard.h"
#include "Snake.h"
#include "Fruit.h"
#include "Printer.h"
//#include "World.h"

int main(void) {
  Keyboard keyboard;
  Snake snake;
  Fruit fruit;
  Printer printer;
  //World world;

  while ( keyboard.key != Keyboard::keys::esc) {
    keyboard.input();
    
    fruit.generate();
    fruit.write(printer);

    snake.set_direction(keyboard.key, printer);
    snake.write(printer);

    printer.print();
  }
  return 0;
}
