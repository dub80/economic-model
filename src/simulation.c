#include "stdlib.h"
#include "./simulation.h"

simulation *s;

simulation *initialiseSimulation() {
  s = malloc(sizeof(simulation));
  s->age = 0;
  return s;
}

void simulationTick() {
  s->age += 1;
}

simulation *getSimulation() {
  return s;
}

void clearSimulation() {
  free(s);
}
