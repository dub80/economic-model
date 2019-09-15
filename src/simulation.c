#include "stdlib.h"
#include "./economic-model.h"

simulation *_simulation;
person *_person;

simulation *initialiseSimulation(int year, person *person) {
  _simulation = malloc(sizeof(simulation));
  _simulation->year = year;
  _person = person;

  return _simulation;
}

simulation *getSimulation() {
  return _simulation;
}

person *getPerson() {
  return _person;
}

void simulateYear() {
  _simulation->year += 1;
  personTick(_simulation->year, _person);
}

void simulateYears(int years) {
  for (int i=0; i<years; i++) {
    simulateYear();
  }
}

void clearSimulation() {
  free(_simulation);
  free(_person);
}
