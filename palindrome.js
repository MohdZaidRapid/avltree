const arr = [1, 2, 3, 3, 2, 11];

function palin(arr) {
  let i = 0;
  let j = arr.length - 1;
  while (i < j) {
    if (arr[i] !== arr[j]) {
      return false;
    }
    i++;
    j--;
  }
  return true;
}

console.log(palin(arr));
