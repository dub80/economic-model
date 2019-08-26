#include <stdio.h>
#include <time.h>
#include <string.h>
#include "./actors/person.h"

void initialseActors() {
  struct Person p;
  p.person_id = 1;
  p.name = strdup("Kunal");
  p.income = 100;
  logPerson(p);
}

int main () {
  time_t current_time;
  char* c_time_string;
  
  current_time = time(NULL);
  c_time_string = ctime(&current_time);

  printf("Economic model started on %s\n", c_time_string);
  
  initialseActors();

  return 0;
}
