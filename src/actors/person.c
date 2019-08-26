#include <stdio.h>

struct Person {
  int person_id;
  char *name;
  int income;
};

void raiseIncome(struct Person person, int percent) {
  person.income = person.income * percent;
}

void logPerson(struct Person person) {
  printf("person: { id: %d, name: %s, income: %d }\n",person.person_id,person.name,person.income);
}