/**
 * @param {number} n
 * @return {number}
 */
var numSquares = function (n) {
    const memo = new Array(n + 1).fill(-1);
    const isPerfectSquare = (x) => {
        const sqrt = Math.sqrt(x);
        return sqrt === Math.floor(sqrt);
    };

    const helper = (n) => {
        if (n <= 0) return 0;
        if (isPerfectSquare(n)) return 1;
        if (memo[n] !== -1) return memo[n];

        let minSquares = n;
        for (let i = 1; i * i <= n; i++) {
            minSquares = Math.min(minSquares, 1 + helper(n - i * i));
        }

        memo[n] = minSquares;
        return minSquares;
    };

    return helper(n);
};