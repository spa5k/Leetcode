function coinChange(coins, amount) {
    let result = Number.MAX_SAFE_INTEGER;
    const memo = [];

    function dfs(index, sum, count) {
        if (sum > amount) {
            return;
        }
        if (sum === amount) {
            result = Math.min(result, count);
            return;
        }

        for (let i = index; i < coins.length; i++) {
            const newSum = sum + coins[i];
            const newCount = count + 1;

            if (!memo[newSum] || newCount < memo[newSum]) {
                memo[newSum] = newCount;
                dfs(i, sum + coins[i], count + 1);
            }
        }
    }

    dfs(0, 0, 0);
    return result === Number.MAX_SAFE_INTEGER ? -1 : result;
}