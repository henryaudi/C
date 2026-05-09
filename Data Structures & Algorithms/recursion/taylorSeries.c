#include <stdio.h>

double e(int x, int n)
{
  static double p = 1, f = 1;
  double r;

  if (n == 0)
  {
    return 1;
  }

  r = e(x, n - 1);
  p = p * x;
  f = f * n;
  return r + p / f;
}

double e_loop(int x, int n)
{
  double s = 1;

  for (int i = n; i > 0; i--)
  {
    s = 1 + x * s / i;
  }

  return s;
}

double e_recursion(int x, int n)
{
  static double s = 1;
  if (n == 0)
  {
    return s;
  }

  s = 1 + x * s / n;
  
  return e_recursion(x, n - 1);
}

int main(int argc, char *argv[])
{
  int x = 1, n = 10;
  double result = e(x, n);
  printf("Result: %lf\n", result);

  return 0;
}

