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

    // ���� �� ��������� ������ �������� ������:
      // ����� ����� ���������� � ��� �� �����, ��� � ���������� ������� ������;
      // ����� �� ������ ��������� ���� ������������� ������;
      // ��� ������������� ������ ��������� � ������� �����;
    // ���� �� ��������� ������ �������� ��� �����:
      // �������� ��������;
      // ���� ������������� ������ ��������� � ������� �����;
      // ����� ������ ������ ��� ��������� ���� ������������� ������;
    // ������ ������ ��������� ��������� ������ ������ �� ������, �� �� ����� ������� �������� ����, ��� ������ ����������� �������� ��������� ������, � ������ ������ ����� ������ � ��� ������.

    printer.print();
  }
  return 0;
}
