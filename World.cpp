#include "World.h"

World::World() {}

World::~World() {}

void World::logic(Dot& dot) { keyboard.input(dot); }
void World::logic(DotMoving& dotm) { keyboard.input(dotm); }
