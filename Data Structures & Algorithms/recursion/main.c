#include <stdio.h>

int sum(int n)
{
  if (n == 0)
  {
    return 0;
  }

  return n + sum(n - 1);
}

int sum_equation(int n)
{
  return n * (n + 1) / 2;
}

int sum_loop(int n)
{
  int result = 0;
  for (int i = 1; i <= n; i++)
  {
    result += i;
  }
  return result;
}

int main(int argc, char *argv[])
{
  int result = sum(5);
  printf("Result: %d\n", result);

  return 0;
}
