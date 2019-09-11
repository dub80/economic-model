#ifndef PERSON
#define PERSON

typedef struct {
  int person_id;
  char *name;
  int income;
} person;


void setupPopulation();
person **getPopulation();
int countPopulation();
void clearPopulation();

void raiseIncome(person p, int percent);
void logPerson(person p);

#endif /* PERSON */
