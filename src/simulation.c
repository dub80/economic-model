#include "stdlib.h"
#include "stdio.h"
#include "./economic-model.h"

simulation *_simulation;
person **_people;

simulation *initialiseSimulation(int year, person **people) {
  _simulation = malloc(sizeof(simulation));
  _simulation->year = year;
  _people = people;

  return _simulation;
}

simulation *getSimulation() {
  return _simulation;
}

person **getPeople() {
  return _people;
}

void simulateYear() {
  _simulation->year += 1;
  int peopleCount = countPeople(_people);
  for (int i=0; i<peopleCount; i++) {
    personTick(_simulation->year, _people[i]);
  }
}

void simulateYears(int years) {
  for (int i=0; i<years; i++) {
    simulateYear();
  }
}

void clearSimulation() {
  if (_simulation != NULL) {
    free(_simulation);
  }

  if (_people != NULL) {
    free(_people);
  }
}
