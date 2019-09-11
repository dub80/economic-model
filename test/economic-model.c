#include <check.h>
#include <stdio.h>
#include "../src/person.h"
#include "../src/simulation.h"


START_TEST(setup_population)
{
  // arrange
  setupPopulation(150);
  
  // act
  int populationCount = countPopulation();
  person **people = getPopulation();

  // assert
  fail_unless(people[0]->income > 50, "unexpected income");
  fail_unless(populationCount == 150, "incorrect no. of people setup");

  // cleanup
  clearPopulation();
}
END_TEST

START_TEST(simulation_age)
{
  // arrange
  simulation *s = initialiseSimulation();
  
  // act
  // assert
  fail_unless(s->age == 0, "simulation starts at age 0");
  simulationTick();
  fail_unless(s->age == 1, "simulation ages with tick");
}
END_TEST

int main(void)
{
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, setup_population);
  tcase_add_test(tc1_1, simulation_age);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
