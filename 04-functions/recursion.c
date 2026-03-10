#include <stdint.h>
#include <stdio.h>

// 1, 1, 2, 3, 5
int fib(int val)
{

  int mem[val];

  for (int i = 0; i < val; i++)
  {
    if (i == 0 || i == 1) 
    {
      mem[i] = 1;
    }
    else 
    {
      mem[i] = mem[i - 1] + mem[i - 2];
    }
  }

  return mem[val - 1];
}

int fib_rec(int val)
{
  if (val == 0 || val == 1) return 1;

  return fib_rec(val - 1) + fib_rec(val - 2);
}

int fib_opt(int val)
{
  
  if (val == 1 || val == 0) return 1;

  return val + fib_opt(val - 1);
}

int main()
{
  printf("%d\n", fib(500));

  printf("%d\n", fib_opt(499));

  char some_str[] = { "Hello" };
  printf("%s\n", some_str);

  return 0;
}