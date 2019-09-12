#include "stdlib.h"
#include "./economic-model.h"

simulation *s;
person *p;

simulation *initialiseSimulation(int year, person person) {
  s = malloc(sizeof(simulation));
  p = malloc(sizeof(person));

  s->year = year;
  p->birth_year = person.birth_year;
  p->death_year = -1;

  return s;
}

simulation *getSimulation() {
  return s;
}

person *getPerson() {
  return p;
}

void simulateYear() {
  s->year += 1;
  personTick(s->year, p);
}

void simulateYears(int years) {
  for (int i=0; i<years; i++) {
    simulateYear();
  }
}

void clearSimulation() {
  free(s);
  free(p);
}
