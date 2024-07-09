/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum = function (candidates, target) {
    const result = [];

    function dfs(start, state, sum) {
        if (sum === target) {
            result.push([...state]);
            return;
        }

        if (sum > target) {
            return;
        }

        for (let i = start; i < candidates.length; i++) {
            state.push(candidates[i]);
            dfs(i, state, sum+candidates[i]);
            state.pop();
        }
    }
    dfs(0,[],0);
    return result;
};