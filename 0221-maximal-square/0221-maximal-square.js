/**
 * @param {character[][]} matrix
 * @return {number}
 */
var maximalSquare = function (matrix) {
    if (!matrix) return 0;

    const m = matrix.length;
    const n = matrix[0].length;

    let res = 0;

    const dp = Array(m)
        .fill()
        .map(() => Array(n).fill(0));

    for (let r = 0; r < m; r++) {
        dp[r][0] = matrix[r][0];
        res = Math.max(dp[r][0], res);
    }

    for (let c = 0; c < n; c++) {
        dp[0][c] = matrix[0][c];
        res = Math.max(dp[0][c], res);
    }

    for (let r = 1; r < m; r++) {
        for (let c = 1; c < n; c++) {
            if (matrix[r][c] == 0) continue;

            dp[r][c] =
                Math.min(dp[r - 1][c], dp[r][c - 1], dp[r - 1][c - 1]) + 1;
            res = Math.max(dp[r][c], res);
        }
    }
    return res * res;
};