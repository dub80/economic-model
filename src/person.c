#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./economic-model.h"

int getage(int year, person *p) {
  return year - p->birth_year;
}
