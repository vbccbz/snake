#include "Dot.h"
#include "DotMoving.h"
#include "Snake.h"

//#include "Keyboard.h"
#include "Printer.h"
#include "World.h"

int main(void) {
  // Dot dot(5, 5);
  DotMoving dotm(5, 5);
  Printer printer;
  World world;

  while (1) {
    // world.logic(dot);
    // dot.print_coordinate();
    // printer.write(dot);
    //printer.print();

    world.logic(dotm);
    dotm.print_coordinate();
    
    printer.write(dotm);
    printer.print();
  }
  return 0;
}
