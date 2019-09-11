#ifndef SIMULATION
#define SIMULATION

typedef struct {
  int age;
} simulation;

simulation *initialiseSimulation();
void simulationTick();
simulation *getSimulation();
void clearSimulation();

#endif /* SIMULATION */
