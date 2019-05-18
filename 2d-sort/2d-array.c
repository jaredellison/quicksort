#include <stdio.h>

void printArray(int len, int arr[len])
{
  for (int i = 0; i < len; i++)
  {
    printf(" %d", arr[i]);
  }
}

void fillArray(int lenX, int lenY, int arr[lenX][lenY])
{
  for (int i = 0; i < lenX; i++)
  {
    for (int j = 0; j < lenY; j++)
    {
      int val;
      if (j == 0)
      {
        val = lenX - i;
      }
      else
      {
        val = 0;
      }
      arr[i][j] = val;
    }
  }
}

void print2DArray(int lenX, int lenY, int arr[lenX][lenY])
{
  printf("Elements: \n");
  for (int i = 0; i < lenX; i++)
  {
    printf(" ");
    printArray(lenY, arr[i]);
  }
  printf("\n");
}

int main()
{
#define MAX 8
#define TUPLE_MAX 4
  int arr[MAX][TUPLE_MAX];

  fillArray(MAX, TUPLE_MAX, arr);
  // Print it
  print2DArray(MAX, TUPLE_MAX, arr);
}