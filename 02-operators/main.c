#include <stdio.h>
#include <stdbool.h>

static void boolExample() 
{
  int a = 12;
  int b = 2;

  printf("%d\n", a && b);
  printf("%d\n", a || b);
  printf("%d\n", !a);
}

static int convMinToDays(int min)
{
  const int minPerDay = 24 * 60;
  return min / minPerDay;
}

static int convMinToYears(int min)
{
  const int minPerYear = 365 * 24 * 60;
  return min / minPerYear;
}

static int getIntSize()
{
  return sizeof(int);
}

int main()
{
  printf("Integer size on this system: %d bytes\n", getIntSize());
  return 0;
}
