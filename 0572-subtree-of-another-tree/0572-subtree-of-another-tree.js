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
 * @param {TreeNode} subRoot
 * @return {boolean}
 */
var isSubtree = function(root, subRoot) {
    if (!root) return false;
    
    if (isSameTree(root,subRoot)) return true;
    
    return isSubtree(root.left, subRoot) || isSubtree(root.right, subRoot)
    
};


const isSameTree=(s,t)=> {
    if (!s && !t) return true;
    if (!s || !t) return false;
    if (s.val !== t.val) return false;
    
    return isSameTree(s.left, t.left) && isSameTree(s.right, t.right);
}