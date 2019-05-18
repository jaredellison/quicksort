#include <stdio.h>

void printArray(int *arr, int len)
{
  for (int i = 0; i < len; i++)
  {
    printf(" %d", arr[i]);
  }
}

int main()
{
#define MAX 8
#define TUPLE_MAX 4
  int arr[MAX][TUPLE_MAX];

  // Create 2d Array
  for (int i = 0; i < MAX; i++)
  {
    for (int j = 0; j < TUPLE_MAX; j++)
    {
      int val;
      if (j == 0)
      {
        val = MAX - i;
      }
      else
      {
        val = 0;
      }
      arr[i][j] = val;
    }
  }

  // Print it
  printf("Elements: \n");
  for (int i = 0; i < MAX; i++)
  {
    printf(" ");
    printArray(arr[i], TUPLE_MAX);
  }
  printf("\n");
}