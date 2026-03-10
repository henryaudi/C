#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void reverse_str(char *str)
{
  int left = 0, right = strlen(str) - 1;
  while (left < right)
  {
    char temp = str[left];
    str[left] = str[right];
    str[right] = temp;
    left++;
    right--;
  }
}

char **sort_str_arr(char **arr, int size)
{
  for (int i = 0; i < size; i++)
  {
    for (int j = i + 1; j < size; j++)
    {
      if (strcmp(arr[i], arr[j]) > 0)
      {
        char *temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }

  return arr;
}

int main() 
{
  char str[] = "Java, C, Python, JavaScript";

  char *token = strtok(str, ", ");

  while (token != NULL)
  {
    printf("%s\n", token);
    token = strtok(NULL, ", ");
  }

  return 0;
}
  