#include "Keyboard.h"
#include "Dot.h"
#include "Printer.h"
#include "Snake.h"
#include "Table.h"

int main(void) {
  Dot dot(5, 5);
  Printer printer;
  Keyboard keyboard;
  while (1) {
    keyboard.input(dot);
    dot.print_coordinate();
    printer.write(dot);  // dot.write(arr); // dot.write(printer);
    printer.print();     // print(arr);
  }
  return 0;
}