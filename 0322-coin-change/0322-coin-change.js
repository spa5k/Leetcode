
function coinChange(coins, amount) {
    let memo = new Array(amount + 1).fill(-1);

    function dfs(sum) {
        if (sum === amount) {
            return 0;
        }
        if (sum > amount) {
            return Infinity;
        }
        if (memo[sum] !== -1) {
            return memo[sum];
        }
        let ans = Infinity;
        for (let coin of coins) {
            let result = dfs(sum + coin);
            if (result !== Infinity) {
                ans = Math.min(ans, result + 1);
            }
        }
        return (memo[sum] = ans);
    }

    let result = dfs(0);
    return result === Infinity ? -1 : result;
}
