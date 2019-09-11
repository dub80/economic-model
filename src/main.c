#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "./person.h"
#include "./simulation.h"

int main () {
  simulation *s = initialiseSimulation();

  time_t current_time;
  char* c_time_string;
  
  current_time = time(NULL);
  c_time_string = ctime(&current_time);
  printf("Economic model started on %s\n", c_time_string);

  setupPopulation(100);
  person **people = getPopulation();
  logPerson(*people[0]);

  free(people);
  printf("returning from main\n");
  return 0;
}
