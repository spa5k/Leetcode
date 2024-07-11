/**
 * @param {string} s
 * @return {string[]}
 */

function isValidID(s) {
    if (parseInt(s) > 255 || !s.length) return false;
    if (s.length >= 2 && s[0] === '0') return false;
    return true;
}

/**
 * @param {string} s
 * @return {string[]}
 */
var restoreIpAddresses = function (s) {
    const result = [];
    const state = [];

    function dfs(start) {
        if (state.length === 4 && start === s.length) {
            result.push(state.join('.'));
            return;
        }

        for (let i = 1; i <= 3; i++) {
            if (start + i > s.length) {
                continue;
            }
            const currentString = s.slice(start, start + i);
            if (isValidID(currentString)) {
                state.push(currentString);
                dfs(start + i);
                state.pop();
            }
        }
    }

    dfs(0);
    return result;
};