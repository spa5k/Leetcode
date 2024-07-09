/**
 * @param {number} n
 * @param {number} k
 * @return {number[][]}
 */
var combine = function (n, k) {
    const result = [];
    const state = [];

    function dfs(start) {
        if (state.length === k) {
            result.push([...state]);
            return;
        }

        for (let i = start; i <= n; i++) {
            state.push(i);
            dfs(i + 1);
            state.pop();
        }
    }
    dfs(1);
    return result;
};