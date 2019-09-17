#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "./economic-model.h"

int main () {
  person *p = makePerson(2000, -1, 100);
  person **people = malloc(2 * sizeof(person));
  people[0] = p;
  people[1] = NULL;

  simulation *s = initialiseSimulation(2020, people);

  time_t current_time;
  char *c_time_string;
  
  current_time = time(NULL);
  c_time_string = ctime(&current_time);
  printf("Economic model started on %s\n", c_time_string);

  clearSimulation(s);
  printf("returning from main\n");
  return 0;
}
