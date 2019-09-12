#include "stdlib.h"
#include "./economic-model.h"

simulation *s;

simulation *initialiseSimulation(int year) {
  s = malloc(sizeof(simulation));
  s->year = year;
  return s;
}

void simulationTick() {
  s->year += 1;
}

simulation *getSimulation() {
  return s;
}

void clearSimulation() {
  free(s);
}
