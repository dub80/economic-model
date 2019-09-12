#ifndef SIMULATION
#define SIMULATION

typedef struct {
  int year;
} simulation;

simulation *initialiseSimulation();
void simulationTick();
simulation *getSimulation();
void clearSimulation();

#endif /* SIMULATION */
