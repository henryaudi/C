#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void foo(char **ptr)
{
  *ptr = malloc(255);
  strcpy(*ptr, "Hello, World!");
}

void send(void *p_data, int s32_size);

int main(void)
{
  char *message = NULL;
  foo(&message);
  send(message, strlen(message));

  int *val = malloc(sizeof(int));
  *val = 42;
  send(val, sizeof(int));

  free(message);
  free(val);

  return 0;
}

