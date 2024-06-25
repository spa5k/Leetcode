/**
 * @param {number[]} nums
 * @return {number[]}
 */
var majorityElement = function(nums) {
    const n = nums.length;
    const threshold = Math.floor(n / 3);
    const counts = {};
    const result = [];

    for (let num of nums) {
        counts[num] = (counts[num] || 0) + 1;
    }

    for (let num in counts) {
        if (counts[num] > threshold) {
            result.push(Number(num));
        }
    }

    return result;
};