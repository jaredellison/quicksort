#include <stdio.h>

#define MAX_X 8
#define MAX_Y 4

// Prototypes
void swap(int array[MAX_X][MAX_Y], int a, int b);
int partition(int array[MAX_X][MAX_Y], int pivot, int left, int right);
void quickSort(int array[MAX_X][MAX_Y], int left, int right);

void fillArray(int lenX, int lenY, int arr[lenX][lenY]);
void fillArrayInteractive(int lenX, int lenY, int arr[lenX][lenY]);

void printArray(int len, int arr[len]);
void print2DArray(int lenX, int lenY, int arr[lenX][lenY]);
void printLine();

////////////////////
//  Sorting

void swap(int array[MAX_X][MAX_Y], int a, int b)
{
  int temp[MAX_Y];

  for (int i = 0; i < MAX_Y; i++)
  {
    temp[i] = array[a][i];
    array[a][i] = array[b][i];
    array[b][i] = temp[i];
  }
}

int partition(int array[MAX_X][MAX_Y], int pivot, int left, int right)
{
  int pivotValue = array[pivot][0];
  int partitionIndex = left;

  for (int i = left; i < right; i++)
  {
    if (array[i][0] < pivotValue)
    {
      swap(array, i, partitionIndex);
      partitionIndex++;
    }
  }
  swap(array, right, partitionIndex);

  return partitionIndex;
}

void quickSort(int array[MAX_X][MAX_Y], int left, int right)
{
  if (left < right)
  {
    int pivot = right;
    int partitionIndex = partition(array, pivot, left, right);

    // sort left
    quickSort(array, left, partitionIndex - 1);
    // sort right
    quickSort(array, partitionIndex + 1, right);
  }
}

////////////////////
//  Helpers

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

void fillArrayInteractive(int lenX, int lenY, int arr[lenX][lenY])
{
  printf("Enter value for element:\n");
  for (int i = 0; i < lenX; i++)
  {
    for (int j = 0; j < lenY; j++)
    {
      int val;
      if (j == 0)
      {
        printf("  [%d][0]: ", i);
        scanf("%d", &val);
      }
      else
      {
        val = 0;
      }
      arr[i][j] = val;
    }
  }
  printf("\n");
}

////////////////////
//  Printing

void printArray(int len, int arr[len])
{
  for (int i = 0; i < len; i++)
  {
    printf(" %d", arr[i]);
  }
}

void print2DArray(int lenX, int lenY, int arr[lenX][lenY])
{
  for (int i = 0; i < lenX; i++)
  {
    printf(" ");
    printArray(lenY, arr[i]);
  }
  printf("\n");
}

void printLine()
{
  for (int i = 0; i < 20; i++)
  {
    printf("-");
  }
  printf("\n");
}

////////////////////
//  Main

int main()
{
  int arr[MAX_X][MAX_Y];

  fillArrayInteractive(MAX_X, MAX_Y, arr);

  printf("Initial Array: \n");
  print2DArray(MAX_X, MAX_Y, arr);

  printf("Sorted: \n");
  quickSort(arr, 0, MAX_X - 1);

  print2DArray(MAX_X, MAX_Y, arr);
}
