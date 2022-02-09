#include "World.h"

World::World(void) { 
  memset(table, '-', 100); 
}

World::~World(void) {}

void World::write(Printer& printer) {
  for (size_t i = 0; i < 100; i++) {
    printer.buffer[i] = table[i];
  }
  return;
}