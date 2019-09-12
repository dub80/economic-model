#include <check.h>
#include <stdio.h>
#include "../src/economic-model.h"


START_TEST(simulation_age)
{
  // arrange
  simulation *s = initialiseSimulation(2010);
  
  // act
  // assert
  fail_unless(s->year == 2010, "simulation starts at year 2010");
  simulationTick();
  fail_unless(s->year == 2011, "simulation ages a year to 2011");

  // cleanup
  clearSimulation();
}
END_TEST

START_TEST(person_getAge)
{
  // arrange
  person p = { 2010 };

  // act
  int age = getAge(2050, &p);

  // assert
  fail_unless(age == 40, "getage returns correct age");
}
END_TEST

START_TEST(simulation_person_aging)
{
  // arrange
  simulation *s = initialiseSimulation(2015);
  person p = { 2008 };

  // act
  simulationTick();

  // assert
  fail_unless(getAge(s->year, &p) == 8, "person ages a year");

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
  tcase_add_test(tc1_1, simulation_age);
  tcase_add_test(tc1_1, simulation_person_aging);
  tcase_add_test(tc1_1, person_getAge);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
