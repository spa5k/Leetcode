/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function (nums, target) {
  const map = {};
  for (let i = 0; i < nums.length; i++) {
    const num = nums[i];
    const neededNumber = target - num;
    if (map[neededNumber] !== undefined) {
      return [map[neededNumber], i];
    }
    map[num] = i;
  }
  return [];
};