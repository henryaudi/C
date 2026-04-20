#include <stdio.h>



int main()
{
  union mixed x = {0};  // Initialize the union to zero.
  union mixed y = 
  {
    .i = 42,
    .f = 3.14f,  // This will overwrite the previous value of i.
    .c = 'B'     // This will overwrite the previous value of f.
  };

  printf("As char: %c\n", y.c);
  printf("As float: %f\n", y.f);
  printf("As int: %d\n", y.i);

  x.f = 1.23f;
  printf("\nAssigned float 1.23 to union member f.\n");
  printf("As char: %c\n", x.c);
  printf("As float: %f\n", x.f);
  printf("As int: %d\n", x.i);

  return 0;
}

