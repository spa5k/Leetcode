/**
 * @param {number} target
 * @param {number[]} nums
 * @return {number}
 */
var minSubArrayLen = function (target, nums) {
  let minLength = Infinity; // Initialize the minimum length as infinity
  let sum = 0; // Initialize the current sum
  let left = 0; // Left pointer of the sliding window

  for (let right = 0; right < nums.length; right++) {
    sum += nums[right]; // Expand the window by adding the current element

    while (sum >= target) {
      // Shrink the window as much as possible while the sum is still >= target
      minLength = Math.min(minLength, right - left + 1); // Update the minimum length
      sum -= nums[left]; // Remove the leftmost element from the sum
      left++; // Move the left pointer to the right
    }
  }

  return minLength === Infinity ? 0 : minLength;
};
