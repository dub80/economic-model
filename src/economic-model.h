#ifndef ECONOMIC_MODEL
#define ECONOMIC_MODEL

typedef struct {
  int year;
} simulation;

typedef struct {
  int openness;
  int conscientiousness;
  int extraversion;
  int agreeableness;
  int neuroticism;
} personality;

typedef enum {
  EDUCATION,
  PROFESSIONAL_PRIMARY,
  PROFESSIONAL_SECONDARY,
  PROFESSIONAL_TERTIARY
} experience_category;

typedef enum {
  LOW,
  MEDIUM,
  HIGH
} experience_level;

typedef struct {
  int year;
  int progress;
  experience_category category;
  experience_level level;
} experience;

typedef struct {
  int birth_year;
  int death_year;
  int iq;
  personality *personality;
  experience **experience;
} person;

// simulation
simulation *initialiseSimulation(int year, person **people);
simulation *getSimulation();
person *getPerson();
void simulateYear();
void simulateYears(int years);
void clearSimulation();

// person
int getAge(int year, person *p);
void personTick(int year, person *p);
person *makePerson(int birthYear, int deathYear, int iq, personality *personality);
int countPeople(person **people);

#endif /* ECONOMIC_MODEL */
