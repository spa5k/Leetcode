/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function (nums, target) {
  let left = 0;
  let right = nums.length - 1;

  while (left <= right) {
    let mid = Math.floor((left + right) / 2);
    let midN = nums[mid];
    if (midN === target) {
      return mid;
    } else if (midN < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return -1;
};