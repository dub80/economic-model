#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include "../src/economic-model.h"

// person
START_TEST(person_getAge)
{
  // arrange
  personality _personality = { 3, 3, 3, 3, 3 };
  person *_person = makePerson(2010, -1, 100, &_personality);

  // act
  int age = getAge(2050, _person);

  // assert
  fail_unless(age == 40, "getage returns correct age");

  // cleanup
  free(_person);
}
END_TEST

START_TEST(person_deceased_age) {
  // arrange
  personality _personality = { 3, 3, 3, 3, 3 };
  person *_person = makePerson(1970, 2015, 95, &_personality);
  
  // act
  // assert
  fail_unless(getAge(2050, _person) == 45, "person should stop aging once deceased");

  // cleanup
  free(_person);
}
END_TEST

START_TEST(person_define_personality) {
  // arrange
  personality _personality = { 1, 2, 3, 4, 5 };
  person *_person = makePerson(2000, -1, 102, &_personality);

  // act
  // assert
  fail_unless(_person->personality->agreeableness  == 4, "agreeableness set correctly");
  fail_unless(_person->personality->openness  == 1, "openness set correctly");

  // cleanup
  free(_person);
}
END_TEST

START_TEST(person_define_iq) {
  // arrange
  personality _personality = { 1, 2, 3, 4, 5 };
  person *_person = makePerson(1987, -1, 115, &_personality);

  // act
  // assert
  fail_unless(_person->iq  == 115, "iq set correctly");

  // cleanup
  free(_person);
}
END_TEST

START_TEST(person_define_experience)
{
  // arrange
  personality _personality = { 1, 2, 3, 4, 5 };
  person *_person = makePerson(1987, -1, 115, &_personality);

  experience education = { 2000, 5, EDUCATION, LOW };
  experience professional = { 2001, 8, PROFESSIONAL_PRIMARY, LOW };
  experience **history = malloc(3 * sizeof(experience));
  history[0] = &education;
  history[1] = &professional;
  history[2] = NULL;

  _person->experience = history;

  // act
  // assert
  fail_unless(_person->experience[0]->category == EDUCATION, "category set correctly");
  fail_unless(_person->experience[0]->year == 2000, "year set correctly");
  fail_unless(_person->experience[1]->growth == 8, "progress set correctly");

  // cleanup
  free(history);
  free(_person);
}
END_TEST

START_TEST(person_get_experience_value)
{
  // arrange
  personality _personality = { 3, 3, 3, 3, 3 };
  person *_person = makePerson(2000, -1, 100, &_personality);
  experience_option _option = { 2001, EDUCATION, LOW };

  // act
  int growth = getGrowthFromExperience(&_option, _person);

  // assert
  fail_unless(growth >= 1, "minimum of 1");

  // cleanup
  free(_person);
}
END_TEST

// opportunity
START_TEST(opportunity_getNextOpportunity)
{
  // arrange
  personality _personality = { 3, 3, 3, 3, 3 };
  person *_person = makePerson(2000, -1, 110, &_personality);
  _person->experience = NULL;

  // act
  experience_option *_option = getNextOpportunity(2020, _person);
  
  // assert
  fail_unless(_option->category == EDUCATION, "default experience category should be EDUCATION");
  fail_unless(_option->level == LOW, "default experience level should be LOW");

  // cleanup
  free(_person);
  free(_option);
}
END_TEST

// simulation
START_TEST(simulation_age)
{
  // arrange
  personality _personality = { 1, 2, 3, 4, 5 };
  person *_person = makePerson(2000, -1, 105, &_personality);
  person **people = malloc(2 * sizeof(person));
  people[0] = _person;
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
  personality _personality = { 1, 2, 3, 4, 5 };
  person *_person = makePerson(2008, -1, 130, &_personality);
  person **_people = malloc(2 * sizeof(person));
  _people[0] = _person;
  _people[1] = NULL;
  simulation *s = initialiseSimulation(2015, _people);

  // act
  simulateYear();

  // assert
  fail_unless(getAge(s->year, _person) == 8, "person ages a year");

  // cleanup
  clearSimulation();
}
END_TEST

START_TEST(simulation_people_life_expectancy)
{
  // arrange
  personality _personality = { 1, 2, 3, 4, 5 };
  person *_person1 = makePerson(2010, -1, 120, &_personality);
  person *_person2 = makePerson(2006, -1, 97, &_personality);
  person **_people = malloc(3 * sizeof(person));
  _people[0] = _person1;
  _people[1] = _person2;
  _people[2] = NULL;
  initialiseSimulation(2021, _people);

  // act
  simulateYears(150);

  // assert
  fail_unless(_person1->death_year > -1, "person p1 should be deceased");
  fail_unless(_person2->death_year > -1, "person p2 should be deceased");

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
  tcase_add_test(tc1_1, person_deceased_age);
  tcase_add_test(tc1_1, person_define_personality);
  tcase_add_test(tc1_1, person_define_iq);
  tcase_add_test(tc1_1, person_define_experience);
  tcase_add_test(tc1_1, person_get_experience_value);

  tcase_add_test(tc1_1, opportunity_getNextOpportunity);

  tcase_add_test(tc1_1, simulation_age);
  tcase_add_test(tc1_1, simulation_person_aging);
  tcase_add_test(tc1_1, simulation_people_life_expectancy);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
