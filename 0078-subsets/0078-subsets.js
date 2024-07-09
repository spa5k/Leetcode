/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var subsets = function(nums) {
    const result = [];
    const state = [];
    function dfs(start) {
        result.push(state.slice());

        for (let i = start; i < nums.length; i++) {
            state.push(nums[i]);
            dfs(i + 1);
            state.pop();
        }
    }

    dfs(0);
    return result;
};