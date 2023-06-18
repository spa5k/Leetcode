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
 * @return {number[]}
 */
var rightSideView = function (root) {
  const res = [];
  if (!root) {
    return res;
  }
  const queue = [];
  queue.push(root);

  while (queue.length > 0) {
    const newLevel = [];
    const n = queue.length;

    for (let i = 0; i < n; i++) {
      const node = queue.shift();
      if (node) {
        newLevel.push(node.val);
        if (node.left) {
          queue.push(node.left);
        }
        if (node.right) {
          queue.push(node.right);
        }
      }
    }
    res.push(newLevel[newLevel.length - 1]);
  }
  return res;
};