#include "./economic-model.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
  personality _personality = {3, 3, 3, 3, 3};
  person *_person = makePerson(2000, -1, 100, &_personality);
  person **_people = malloc(2 * sizeof(person));
  _people[0] = _person;
  _people[1] = NULL;

  simulation *s = initialiseSimulation(2020, _people);

  time_t current_time;
  char *c_time_string;

  current_time = time(NULL);
  c_time_string = ctime(&current_time);
  printf("Economic model started on %s\n", c_time_string);

  clearSimulation(s);
  printf("returning from main\n");
  return 0;
}
