#include <stdio.h>
#include <stdlib.h> 

#define int_ptr int *
int_ptr a, b;  // a is type int *, b is type int.

typedef int * int_ptr_t;
int_ptr_t c, d;  // c and d are both of type int *.

int fun()
{
  static int count = 0;

  count++;
  return count;
}

typedef struct 
{
  int x;
  int y;
  int z;
} Point_t;

int main(int argc, char *argv[])
{

  Point_t str_pt1 = {
    .x = 10,
    .y = 20
  };

  Point_t str_pt3 = { 1, 2, 3 };  // If you don;t specify the field, it will assign in order.

  Point_t arr_str_pts[5] = 
  {
    [0] = { .x = 1, .y = 2, .z = 3 },
    [1] = { .x = 4, .y = 5, .z = 6 },
    [2] = { .x = 7, .y = 8, .z = 9 },
     // If you don't specify the field, it will assign in order.
     // The rest of the fields will be initialized to zero.
  };

  printf("str_pt[0]: x = %d, y = %d, z = %d\n", arr_str_pts[0].x, arr_str_pts[0].y, arr_str_pts[0].z);
  printf("str_pt[1]: x = %d, y = %d, z = %d\n", arr_str_pts[1].x, arr_str_pts[1].y, arr_str_pts[1].z);
  printf("str_pt[2]: x = %d, y = %d, z = %d\n", arr_str_pts[2].x, arr_str_pts[2].y, arr_str_pts[2].z);
  printf("str_pt[3]: x = %d, y = %d, z = %d\n", arr_str_pts[3].x, arr_str_pts[3].y, arr_str_pts[3].z);
  printf("str_pt[4]: x = %d, y = %d, z = %d\n", arr_str_pts[4].x, arr_str_pts[4].y, arr_str_pts[4].z);

  return 0;
}

