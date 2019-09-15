#ifndef ECONOMIC_MODEL
#define ECONOMIC_MODEL

typedef struct {
  int year;
} simulation;

typedef struct {
  int birth_year;
  int death_year;
} person;

// simulation
simulation *initialiseSimulation(int year, person *person);
simulation *getSimulation();
person *getPerson();
void simulateYear();
void simulateYears(int years);
void clearSimulation();

// person
int getAge(int year, person *p);
void personTick(int year, person *p);
person *makePerson(int birthYear, int deathYear);

#endif /* ECONOMIC_MODEL */
