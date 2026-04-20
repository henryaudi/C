#include <stdio.h>

struct packed_struct
{
  unsigned int       : 3;
  // unsigned int f1[5] : 5;
  unsigned int f2    : 1;
  unsigned int f3    : 1;
  unsigned int type  : 8;
  unsigned int index : 18;
};

static void print_u8_binary(int n)
{
  printf("0b");

  for (int i = 7; i >= 0; i--)
  {
    printf("%d", (n >> i) & 1);
  }
}

int main(void)
{
  printf("Size of packed_struct: %zu bytes\n", sizeof(struct packed_struct));

  return 0;
}
