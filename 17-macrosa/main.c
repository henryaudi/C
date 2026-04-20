#include <stdio.h>

#define Warning(...) fprintf(stderr, __VA_ARGS__)

#define Max(a, b) ((a) > (b) ? (a) : (b))

int main(void)
{
  int x = 5;
  int y = 10;

  if (__STDC__ == 1) 
  {
    Warning("This code is compiled with C17 standard.\n");
  }
  else 
  {
    Warning("This code is not compiled with C17 standard.\n");
  }

  printf("Date: %s\n", __DATE__);
  printf("Time: %s\n", __TIME__);
  printf("File: %s\n", __FILE__);
  printf("Line: %d\n", __LINE__);

  return 0;
}
