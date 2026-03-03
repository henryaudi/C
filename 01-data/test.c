#include <stdio.h>
#include <stdbool.h>
// int main() 
// {
//   int simple_declare_data;
//   simple_declare_data = 10;

//   int in_line_data_declaration = 1;

//   // You can change variable values
//   in_line_data_declaration = 20;

//   return 0;
// }

// int main()
// {
//   float jason = 23.33f;
//   double henry = 23.3333333333333e12;
  
//   _Bool boolVariable = 1;  // C89 standard
//   bool  bool99Version = true;  // C99 standard

//   return 0;
// }

// int main()
// {
//   enum gender 
//   {
//     MALE,
//     FEMALE,
//   };

//   enum gender myGender = MALE;

//   return 0;
// }

// int main()
// {
//   char myChar  = 'A';
//   char newLine = '\n';
//   float floatNum = 3.23f;

//   printf("The value of floatNum is: %.2f\n", floatNum);  // Output: The value of floatNum is: 3.23
//   printf("%10f\n", floatNum);  // Output: "  3.230000" (right-aligned in a field of width 10)
//   printf("%10.2f\n", floatNum);  // Output: "      3.23" (right-aligned in a field of width 10 with 2 decimal places)
//   return 0;
// }

int main(int argc, char *argv[])
{
  int numberOfArguments = argc;
  char *arg1 = argv[0];  // The first argument is the program name
  char *arg2 = argv[1];  // The second argument (if provided)

  printf("Number of arguments: %d\n", numberOfArguments);
  printf("Argument 1: %s\n", arg1);
  printf("Argument 2: %s\n", arg2);

  return 0;
}
