#include <stdio.h>

////////////////////
//  Functions

void quicksort(int *array, int left, int right);
int partition(int *array, int pivot, int left, int right);
void swap(int *array, int a, int b);
void testSwap();

void swap(int *array, int a, int b)
{
  int temp = array[a];
  array[a] = array[b];
  array[b] = temp;
}

int partition(int *array, int pivot, int left, int right)
{
  int pivotValue = array[pivot];
  int partitionIndex = left;

  for (int i = left; i < right; i++) {
    if (array[i] < pivotValue) {
      swap(array, i, partitionIndex);
      partitionIndex++;
    }
  }
  swap(array, right, partitionIndex);

  return partitionIndex;
}

void quickSort(int *array, int left, int right)
{
  if (left < right) {
    int pivot = right;
    int partitionIndex = partition(array, pivot, left, right);

    // sort left
    quickSort(array, left, partitionIndex - 1);
    // sort right
    quickSort(array, partitionIndex + 1, right);
  }
}


////////////////////
//  Tests and Helpers

void testSwap() {
  int arr[2] = {2, 1};

  swap(arr, 0, 1);

  printf("Expect 1, 2:  [%d, %d]\n", arr[0], arr[1]);
}

void printArray(int *arr, int len) {
  for (int i = 0; i < len; i++)
  {
    printf(" %d", arr[i]);
  }
  printf("\n");
}

void printLine() {
  for (int i = 0; i < 20; i++)
  {
    printf("-");
  }
  printf("\n");
}

////////////////////
//  Main

int main() {
  int arrLength = 5;
  int arrA[5] = {5, 2, 3, 4, 1};
  int arrB[5] = {5, 4, 3, 2, 1};
  int arrC[5] = {1, 3, 2, 5, 4};

  printf("Before: ");
  printArray(arrA, arrLength);
  printf("Expect: [1,2,3,4,5]\n");
  quickSort(arrA, 0, arrLength - 1);
  printArray(arrA, arrLength);
  printLine();

  printf("Before: ");
  printArray(arrB, arrLength);
  printf("Expect: [1,2,3,4,5]\n");
  quickSort(arrB, 0, arrLength - 1);
  printArray(arrB, arrLength);
  printLine();

  printf("Before: ");
  printArray(arrC, arrLength);
  printf("Expect: [1,2,3,4,5]\n");
  quickSort(arrC, 0, arrLength - 1);
  printArray(arrC, arrLength);
  printLine();
}

