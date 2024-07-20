/**
 * @param {number[][]} triangle
 * @return {number}
 */
var minimumTotal = function(triangle) {
    const n = triangle.length;

    const memo = Array(n)
        .fill()
        .map(() => Array(n).fill(Number.MAX_SAFE_INTEGER));

    function dfs(level, column) {
        if (level === n) return 0;
        if (memo[level][column] != Number.MAX_SAFE_INTEGER) {
            return memo[level][column];
        }

        let left = dfs(level + 1, column);
        let right = dfs(level + 1, column + 1);
        memo[level][column] = Math.min(left, right) + triangle[level][column];
        return memo[level][column];
    }
    return dfs(0, 0);
     
};