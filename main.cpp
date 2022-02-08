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

    // ���� �� ��������� ������ �������� ������:
      // ����� ����� ���������� � ��� �� �����, ��� � ���������� ������� ������;
      // ����� �� ������ ��������� ���� ������������� ������;
      // ��� ������������� ������ ��������� � ������� �����;
    // ���� �� ��������� ������ �������� ��� �����:
      // �������� ��������;
      // ���� ������������� ������ ��������� � ������� �����;
      // ����� ������ ������ ��� ��������� ���� ������������� ������;
    // ������ ������ ��������� ��������� ������ ������ �� ������, �� �� ����� ������� �������� ����, ��� ������ ����������� �������� ��������� ������, � ������ ������ ����� ������ � ��� ������.

    fruit.write(printer);
    snake.move(keyboard.key, printer, fruit);
    snake.write(printer);

    printer.print();
  }
  return 0;
}
