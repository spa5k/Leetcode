var combinationSum2 = function (candidates, target) {
    const result = [];
    const state = [];
    const memo = new Set();

    candidates.sort((a, b) => a - b);

    function dfs(start, sum) {
        if (sum === target) {
            const combination = state.slice().join(',');
            if (!memo.has(combination)) {
                result.push([...state]);
                memo.add(combination);
            }
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