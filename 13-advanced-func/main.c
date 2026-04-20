#include <stdarg.h>
#include <math.h>
#include <stdio.h>

double average(double v1, double v2, ...);

double sample_stddev(int count, ...);

int factorial(int n)
{
  int res = 0;

  if (n == 0)
    res = 1;
  else
    res = n * factorial(n - 1);

  return res;
}

int main(void)
{
  double stdev = sample_stddev(5, 10.0, 12.0, 23.0, 23.0, 16.0);
  printf("Standard Deviation: %f\n", stdev);

  return 0;
}

double sample_stddev(int count, ...)
{
  double sum = 0.0;

  va_list args1;
  va_start(args1, count);

  va_list args2;
  va_copy(args2, args1);  // Create a copy of the va_list.

  for (int i = 0; i < count; i++)
  {
    sum += va_arg(args1, double);
  }

  va_end(args1);  // Clean up the first va_list.

  double mean = sum / count;
  double sum_sq_diff = 0;

  for (int i = 0; i < count; i++)
  {
    double val = va_arg(args2, double);
    sum_sq_diff += (val - mean) * (val - mean);
  }

  va_end(args2);  // Clean up the second va_list.

  return sqrt(sum_sq_diff / (count));
}

double average(double v1, double v2, ...)
{
  va_list ptr_args;
  double sum = v1 + v2;
  double val_arg = 0.0;

  int count = 2;
  va_start(ptr_args, v2);

  while ((val_arg = va_arg(ptr_args, double)) != -1.0)
  {
    sum += val_arg;
    count++;
  }

  va_end(ptr_args);  // Clean up the va_list

  return sum / count;
}
