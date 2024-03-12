function max_sum(nums, k) {
  //   let count = 0;
  let maxi = -Infinity;
  for (let i = 0; i < nums.length; i++) {
    let sum = 0;
    let count = 1;
    sum += nums[i];
    for (let j = i + 1; j < nums.length; j++) {
      if (count == k) {
        break;
      }
      sum += nums[j];
      count++;
    }
    maxi = Math.max(sum, maxi);
  }
  return maxi;
}

function max_optimize(nums, k) {
  let i = 0;
  let j = 0;
  let sum = 0;
  let maxi = -Infinity;
  while (j < nums.length) {
    sum += nums[j];
    if (j - i + 1 == k) {
      maxi = Math.max(maxi, sum);
      sum = sum - nums[i];
      i++;
    }
    j++;
  }
  return maxi;
}
let arr = [1, 2, 3, 4, 5, 6];
// console.log(max_sum(arr, 3));
console.log(max_optimize(arr, 3));
