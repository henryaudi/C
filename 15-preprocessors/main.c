#include <stdio.h>

int main(void)
{
  #if !SOME_RANDOM_MACRO
    printf("Some random undefined macro.\n");
  #endif

  return 0;
}
