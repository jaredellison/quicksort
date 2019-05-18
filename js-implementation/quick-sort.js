const quickSort = array => {
  if (array.length <= 1) return array;

  const pivot = array[0];
  let left = [];
  let right = [];

  for (let i = 1; i < array.length; i++) {
    const element = array[i];
    if (element < pivot) {
      left.push(element);
    } else {
      right.push(element);
    }
  }

  left = quickSort(left);
  right = quickSort(right);

  return left.concat(pivot, right);
};

let unsorted = [5, 2, 3, 4, 1];
console.log('Expect [1,2,3,4,5]:', quickSort(unsorted, 0, unsorted.length - 1));
unsorted = [5,4,3,2,1];
console.log('Expect [1,2,3,4,5]:', quickSort(unsorted, 0, unsorted.length - 1));
unsorted = [1,3,2,5,4];
console.log('Expect [1,2,3,4,5]:', quickSort(unsorted, 0, unsorted.length - 1));
