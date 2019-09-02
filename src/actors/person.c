#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int person_id;
  char *name;
  int income;
} person;

person **people;

void setupPopulation(int count) {
  people = malloc((count + 1) * sizeof(*people));

  for (int i = 0; i < count; i++) {
    if (i < count) {
      char name[20];
      snprintf(name, 20, "person-%d", i);

      person *p = malloc(sizeof(person));
      p->person_id = i;
      p->income = (i + 100) * 2;
      p->name = strdup(name);
      people[i] = p;
    } else {
      people[i] = NULL;
    }
  }
}

person **getPopulation() {
  return people;
}

int countPopulation() {
  int i = 0;
  while (1) {
    if (people[i] == NULL) {
      return i;
    }
    i++;
  }
}

void clearPopulation() {
  free(people);
}

void raiseIncome(person p, int percent) {
  p.income = p.income * percent;
}

void logPerson(person p) {
  printf("person: { id: %d, name: %s, income: %d }\n",p.person_id,p.name,p.income);
}