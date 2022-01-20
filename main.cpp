#include "Dot.h"
#include "DotMoving.h"
#include "Snake.h"

#include "Printer.h"
#include "World.h"

int main(void) {
  // Dot dot(5, 5);
  //DotMoving dotm(5, 5);
  Snake snake ;

  Printer printer;
  World world;

  while (1) {
    // world.logic(dot);
    // dot.print_coordinate();
    // printer.write(dot);

    //world.logic(dotm);
    //dotm.print_coordinate();
    //printer.write(dotm);

    world.logic(snake);
    printer.write(snake);
    printer.print();
  }
  return 0;
}
