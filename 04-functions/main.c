#include <stdio.h>
#include "func_defines.h"

FileScop int add(int, int);

GlobScop int main()
{
  int a = 10, b = 20;
  int sum = add(a, b);
  printf("Sum of %d and %d is %d\n", a, b, sum);
  return 0;
}

FileScop int add(int x, int y)
{
  return x + y;
}

FileScop void print_message()
{
  const char *message = "Hello from a static function!";
  printf("%s\n", &message[0]);
}

