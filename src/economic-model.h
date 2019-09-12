#ifndef ECONOMIC_MODEL
#define ECONOMIC_MODEL

// simulation
typedef struct {
  int year;
} simulation;

simulation *initialiseSimulation();
void simulationTick();
simulation *getSimulation();
void clearSimulation();

// people
typedef struct {
  int birth_year;
} person;

int getage(int year, person *p);

#endif /* ECONOMIC_MODEL */
