#include <stdio.h>

void funA(int n);
void funB(int n);

int main(void)
{
  int x = 10;
  funA(x);

  return 0;
}

void funA(int n)
{
  if (n > 0)
  {
    printf("A: %d\n", n);
    funB(n - 1);
  }
}

void funB(int n)
{
  if (n > 0)
  {
    printf("B: %d\n", n);
    funA(n / 2);
  }
}
