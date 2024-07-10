/**
 * @param {string} s
 * @param {string[]} wordDict
 * @return {boolean}
 */
var wordBreak = function (s, wordDict) {
    const memo = {};

    function dfs(startIndex) {
        if (startIndex === s.length) return true;

        if (startIndex in memo) return memo[startIndex];

        let ans = false;
        for (const word of wordDict) {
            if (s.slice(startIndex).startsWith(word)) {
                if (dfs(startIndex + word.length)) {
                    ans = true;
                    break;
                }
            }
        }
        memo[startIndex] = ans;
        return ans;
    }

    return dfs(0);
};