#include "Keyboard.h"
#include "Snake.h"
#include "Fruit.h"
#include "Printer.h"

int main(void) {
  Keyboard keyboard;
  Snake snake;
  Fruit fruit;
  Printer printer;

  while ( keyboard.key != Keyboard::keys::esc) {
    keyboard.input();
    
    fruit.write(printer);

    snake.move(keyboard.key, printer, fruit);
    snake.write(printer);

    printer.print();
  }
  return 0;
}
