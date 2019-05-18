const quickSort = (array, left, right) => {
  if (left < right) {
    let pivot = right;
    let partitionIndex = partition(array, pivot, left, right);

    // sort left
    quickSort(array, left, partitionIndex - 1);
    // sort right
    quickSort(array, partitionIndex + 1, right);
  }
  return array;
};

const partition = (array, pivot, left, right) => {
  let pivotValue = array[pivot];
  let partitionIndex = left;

  for (let i = left; i < right; i++) {
    if (array[i] < pivotValue) {
      swap(array, i, partitionIndex);
      partitionIndex++;
    }
  }
  swap(array, right, partitionIndex);

  return partitionIndex;
};

const swap = (array, a, b) => {
  let temp = array[a];
  array[a] = array[b];
  array[b] = temp;
  return array;
};

let unsorted = [5, 2, 3, 4, 1];
console.log('Expect [1,2,3,4,5]:', quickSort(unsorted, 0, unsorted.length - 1));
unsorted = [5, 4, 3, 2, 1];
console.log('Expect [1,2,3,4,5]:', quickSort(unsorted, 0, unsorted.length - 1));
unsorted = [1, 3, 2, 5, 4];
console.log('Expect [1,2,3,4,5]:', quickSort(unsorted, 0, unsorted.length - 1));

////////////////////
//
