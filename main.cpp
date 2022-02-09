#include "Keyboard.h"
#include "World.h"
#include "Printer.h"
#include "Snake.h"
#include "Fruit.h"
int main(void) {
  Keyboard keyboard;
  Printer printer;

  World world;
  Snake snake(world);
  Fruit fruit(world);

  while ( keyboard.key != Keyboard::keys::esc) {
    keyboard.input();
    fruit.generate(world);
    snake.move(keyboard.key, world);
    world.write(printer);

    // Если за генерацию фрукта отвечает змейка:
      // новый фрукт появляется в том же кадре, что и поглощение старого фрукта;
      // фрукт не обязан проверять факт существования фрукта;
      // нет необходимости вызова генерации в главном цикле;
    // Если за генерацию фрукта отвечает сам фрукт:
      // выглядит логичнее;
      // есть необходимость вызова генерации в главном цикле;
      // фрукт обязан каждый раз проверять факт существования фрукта;
    // Второй способ позволяет запретить змейке доступ ко фрукту, но всё равно остаётся проблема того, что змейка поглощением изменяет состояние фрукта, а значит должна иметь доступ к его данным.

    printer.print();
  }
  return 0;
}
