#include <stdio.h>
#include <time.h>

int main () {
  time_t current_time;
  char* c_time_string;
  
  current_time = time(NULL);
  c_time_string = ctime(&current_time);
  
  printf("Economic model started on %s\n", c_time_string);
  return 0;
}
