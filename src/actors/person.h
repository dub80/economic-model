#ifndef PERSON
#define PERSON

struct Person {
  int person_id;
  char *name;
  int income;
};

// struct Person *initialisePeople(int k);
void raiseIncome(struct Person person, int percent);
// void logPeople(struct Person people[]);
void logPerson(struct Person person);

#endif /* PERSON */
