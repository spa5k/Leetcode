var combinationSum2 = function (candidates, target) {
    const result = [];
    const state = [];
    const memo = {};
    candidates.sort();

    function dfs(start, sum) {
        if (sum === target && !memo[state.join('')]) {
            result.push([...state]);
            memo[state.join('')] = true;

            return;
        }
        if (memo[state.join('')]) {
            return;
        }

        if (sum > target) {
            return;
        }

        for (let i = start; i < candidates.length; i++) {
            if (i > start && candidates[i] === candidates[i - 1]) {
                continue;
            }
            
            state.push(candidates[i]);
            dfs(i + 1, sum + candidates[i]);
            state.pop();
        }
    }
    dfs(0, 0);
    return result;
};