#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include "../src/economic-model.h"

START_TEST(person_getAge)
{
  // arrange
  person *p = makePerson(2010, -1);

  // act
  int age = getAge(2050, p);

  // assert
  fail_unless(age == 40, "getage returns correct age");

  // cleanup
  free(p);
}
END_TEST

START_TEST(simulation_age)
{
  // arrange
  person *p = makePerson(2000, -1);
  person **people = malloc(2 * sizeof(person));
  people[0] = p;
  people[1] = NULL;
  simulation *s = initialiseSimulation(2010, people);
  
  // act
  // assert
  fail_unless(s->year == 2010, "simulation starts at year 2010");
  simulateYear();
  fail_unless(s->year == 2011, "simulation ages a year to 2011");

  // cleanup
  clearSimulation();
}
END_TEST

START_TEST(simulation_person_aging)
{
  // arrange
  person *p = makePerson(2008, -1);
  person **people = malloc(2 * sizeof(person));
  people[0] = p;
  people[1] = NULL;
  simulation *s = initialiseSimulation(2015, people);

  // act
  simulateYear();

  // assert
  fail_unless(getAge(s->year, p) == 8, "person ages a year");

  // cleanup
  clearSimulation();
}
END_TEST

START_TEST(simulation_people_life_expectancy)
{
  // arrange
  person *p1 = makePerson(2010, -1);
  person *p2 = makePerson(2006, -1);
  person **people = malloc(3 * sizeof(person));
  people[0] = p1;
  people[1] = p2;
  people[2] = NULL;
  initialiseSimulation(2021, people);

  // act
  simulateYears(150);

  // assert
  fail_unless(p1->death_year > -1, "person p1 should be deceased");
  fail_unless(p2->death_year > -1, "person p2 should be deceased");

  // cleanup
  clearSimulation();
}
END_TEST

START_TEST(person_deceased_age) {
  // arrange
  person *p = makePerson(1970, 2015);
  
  // act
  // assert
  fail_unless(getAge(2050, p) == 45, "person should stop aging once deceased");

  // cleanup
  free(p);
}
END_TEST

int main(void)
{
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, person_getAge);
  tcase_add_test(tc1_1, simulation_age);
  tcase_add_test(tc1_1, simulation_person_aging);
  tcase_add_test(tc1_1, simulation_people_life_expectancy);
  tcase_add_test(tc1_1, person_deceased_age);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
