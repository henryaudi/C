#include <stdio.h>
#include <stdlib.h>


int fib(int n)
{
  if (n <= 1)
  {
    return n;
  }
  
  int memo[n + 1];
  memo[0] = 0;
  memo[1] = 1;

  for (int i = 2; i <= n; i++)
  {
    memo[i] = memo[i - 1] + memo[i - 2];
  }

  return memo[n];
}

int main(void)
{
  int n = 10;
  int result = fib(n);
  printf("Fibonacci of %d is %d\n", n, result);
  return 0;
}

