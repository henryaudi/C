#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

void handler_divideByZero(int sigNum);

void hello()
{
  printf("Hello, World!\n");
}

int main()
{
  int res = 0;
  int v1 = 0, v2 = 0;

  void (*sigHandlerReturn)(int);

  sigHandlerReturn = signal(SIGFPE, handler_divideByZero);

  if (sigHandlerReturn == SIG_ERR)
  {
    printf("Error setting signal handler for SIGFPE\n");
    return EXIT_FAILURE;
  }

  v1 = 121;
  v2 = 0;

  res = v1 / v2;

  printf("Result: %d\n", res);

  return 0;
}

void handler_divideByZero(int sigNum)
{
  if (sigNum == SIGFPE)
  {
    printf("Caught signal: SIGFPE (divide by zero)\n");
    exit(EXIT_FAILURE);
  }
  else
  {
    printf("Caught unexpected signal: %d\n", sigNum);
    exit(EXIT_FAILURE);
  }
}
