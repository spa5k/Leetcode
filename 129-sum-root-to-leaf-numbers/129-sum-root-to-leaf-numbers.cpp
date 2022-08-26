/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
  int res = 0;

public:
  int sumNumbers(TreeNode *root)
  {
    helper(root, res);
    cout << res;
    return res;
  }
  void helper(TreeNode *node, int curr)
  {
    if (!node)
      return;

    curr = curr * 10 + node->val;
    if (!node->left && !node->right)
    {
      // This is
      res += curr;
      return;
    }

    helper(node->left, curr);

    helper(node->right, curr);
  }
};