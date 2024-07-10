/**
 * @param {string} s
 * @return {number}
 */
var numDecodings = function (s) {
    if (s.length === 0) return 0;

    let state = 0;
    const memo = new Array(s.length).fill(-1);

    function dfs(start) {
        if (start === s.length) {
            state += 1;
            return;
        }

        if (s[start] === '0') {
            return;
        }

        if (memo[start] !== -1) {
            state += memo[start];
            return;
        }

        dfs(start + 1);

        if (start < s.length - 1) {
            const twoDigit = parseInt(s[start] + s[start + 1], 10);
            if (twoDigit >= 10 && twoDigit <= 26) {
                dfs(start + 2);
            }
        }
        memo[start] = state;
    }

    dfs(0);
    return state;
};