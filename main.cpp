#include "Keyboard.h"
#include "Printer.h"
#include "Snake.h"
#include "Fruit.h"

int main(void) {
  Keyboard keyboard;
  Printer printer;
  Snake snake;
  Fruit fruit;

  while ( keyboard.key != Keyboard::keys::esc) {
    keyboard.input();
    
    //fruit.generate(printer); :-(
    //fruit.write(printer);

    // Если за генерацию фрукта отвечает змейка:
      // новый фрукт появляется в том же кадре, что и поглощение старого фрукта;
      // фрукт не обязан проверять факт существования фрукта;
      // нет необходимости вызова генерации в главном цикле;
    // Если за генерацию фрукта отвечает сам фрукт:
      // выглядит логичнее;
      // есть необходимость вызова генерации в главном цикле;
      // фрукт обязан каждый раз проверять факт существования фрукта;
    // Второй способ позволяет запретить змейке доступ ко фрукту, но всё равно остаётся проблема того, что змейка поглощением изменяет состояние фрукта, а значит должна иметь доступ к его данным.

    fruit.write(printer);
    snake.move(keyboard.key, printer, fruit);
    snake.write(printer);

    printer.print();
  }
  return 0;
}
