#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
  FILE *fp = NULL;

  char buff[255];

  fp = fopen("example.txt", "r");

  while (fscanf(fp, "%s", buff) != EOF)
  {
    printf("1: %s\n", buff);
  }

  fclose(fp);
  return 0;
}
