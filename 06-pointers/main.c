#include <stdio.h>
#include <string.h>
#include <stdint.h>

int main()
{
  int num = 10;
  int *ptr_num = &num;

  num = 21;

  printf("Value of num: %d\n", num);
  printf("Value of ptr_num: %p\n", (void*)ptr_num);
  printf("Value pointed to by ptr_num: %d\n", *ptr_num);
  printf("Size of num: %zu bytes\n", sizeof(*ptr_num));
}