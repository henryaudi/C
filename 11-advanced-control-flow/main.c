#include <stdio.h>
#include <setjmp.h>
#include <stdlib.h>

typedef enum
{
  ERROR = 1,
  SUCCESS = 0
} ControlStatus_t;


jmp_buf buf;

void my_function(void)
{
  printf("Inside my_function.\n");
  longjmp(buf, ERROR);
}

int main()
{
  ControlStatus_t enm_status = setjmp(buf);
  if (enm_status != 0)
  {
    printf("Returned from longjmp with value: %d\n", enm_status);
  }
  else
  {
    printf("Calling my_function.\n");
    my_function();
  }
  return 0;
}
