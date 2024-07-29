/**
 * @param {number} n
 * @return {number}
 */
var numSquares = function (n) {
    const dp = new Array(n + 1).fill(Number.MAX_SAFE_INTEGER);
    dp[0] = 0;
    for (let i = 1; i * i <= n; i++) {
        let cur = i * i;
        for (let j = cur; j <= n; j++) {
            dp[j] = Math.min(dp[j], dp[j - cur] + 1);
        }
    }
    return dp[n];
};