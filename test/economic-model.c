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
  simulation *s = initialiseSimulation(2010, p);
  
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
  simulation *s = initialiseSimulation(2015, p);

  // act
  simulateYear();

  // assert
  fail_unless(getAge(s->year, p) == 8, "person ages a year");

  // cleanup
  clearSimulation();
}
END_TEST

START_TEST(simulation_person_life_expectancy)
{
  // arrange
  person *p = makePerson(2000, -1);
  simulation *s = initialiseSimulation(2020, p);

  // act
  simulateYears(100);

  // assert
  person *agedPerson = getPerson();
  fail_unless(s->year == 2120, "simulation progressed a decade");

  printf("death year: %d\n", agedPerson->death_year);
  fail_unless(agedPerson->death_year > -1, "person deceased");

  // cleanup
  clearSimulation();
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
  tcase_add_test(tc1_1, simulation_person_life_expectancy);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
