#include <check.h>
// #include <stdlib.h>
#include "../src/actors/person.h"


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

int main(void)
{
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, setup_population);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
