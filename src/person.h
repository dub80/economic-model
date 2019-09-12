#ifndef PERSON
#define PERSON

typedef struct {
  int birth_year;
} person;

int getage(int year, person *p);

#endif /* PERSON */
