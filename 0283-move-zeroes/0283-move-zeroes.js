/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var moveZeroes = function (nums) {
  let i = 0;
  for (const n of nums) {
    if (n !== 0) {
      nums[i] = n;
      i++;
    }
  }
  for (let j = i; j < nums.length; j++) {
    nums[j] = 0;
  }
  return nums;
};