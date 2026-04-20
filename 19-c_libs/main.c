#include <stdio.h>
#include <stdlib.h>


int main(void)
{
  char a[20] = "123.456 3.21", *end;
  float val = 0;
  
  val = strtof(a, &end);
  printf("Value: %f\n", val);

  val = strtof(end, NULL);
  printf("Value: %f\n", val);

  return 0;
}

