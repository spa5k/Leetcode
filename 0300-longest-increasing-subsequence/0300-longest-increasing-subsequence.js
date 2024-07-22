function generateSubsets(nums) {
    const res = [[]];
    const state = [];

    function dfs(start) {
        if (start === nums.length) {
            return;
        }

        state.push(nums[start]);
        res.push([...state]);
        dfs(start + 1);
        state.pop();
        dfs(start + 1);
    }

    dfs(0);
    return res;
}

function isIncreasing(nums) {
    for (let i = 1; i < nums.length; i++) {
        if (nums[i - 1] >= nums[i]) {
            return false;
        }
    }
    return true;
}

/**
 * @param {number[]} nums
 * @return {number}
 */
var lengthOfLIS = function (nums) {
    if (nums.length === 0) return 0;

    let dp = new Array(nums.length).fill(1);

    for (let i = 1; i < nums.length; i++) {
        for (let j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = Math.max(dp[i], dp[j] + 1);
            }
        }
    }

    return Math.max(...dp);
};
