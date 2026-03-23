#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int n;
  int arr[10];

  int *restrict ptr_restart = (int *) malloc(10 * sizeof(int));  // Restrict pointer.
  int *par = arr;
  
  for (n = 0; n < 10; n++)
  {
    ptr_restart[n] += 2;
    par[n] += 2;
    par[n] += 3;
    ptr_restart[n] += 3;

    // Note that the compiler can optimize the code for ptr_restart since it's 
    // solely accessed through the restrict pointer, while it cannot optimize the code for par.
    // It might optimize:
    // ptr_restart[n] += 5;
  }

  return 0;
}

