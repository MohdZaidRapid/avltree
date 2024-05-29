const arr = [1, 2, 3, 3, 2, 1,2,3,4,5,6,7,8];

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
