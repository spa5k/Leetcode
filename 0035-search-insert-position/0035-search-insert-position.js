/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function (nums, target) {
  let left = 0;
  let right = nums.length - 1;
  while (left <= right) {
    let mid = Math.floor((left + right) / 2);
    let midn = nums[mid];

    if (midn === target) {
      return mid;
    }
    if (midn < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return left;
};