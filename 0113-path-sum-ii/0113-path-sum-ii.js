/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} targetSum
 * @return {number[][]}
 */
var pathSum = function (root, targetSum) {
    const result = [];
    const state = [];
    function dfs(start, sum) {
        if (!root) {
            return;
        }

        state.push(start.val);
        sum += start.val;

        if (sum === targetSum && !start.left && !start.right) {
            result.push([...state]);
        } else {
            if (start.left) {
                dfs(start.left, sum);
            }
            if (start.right) {
                dfs(start.right, sum);
            }
        }

        state.pop();
    }

    dfs(root, 0);
    return result;
};