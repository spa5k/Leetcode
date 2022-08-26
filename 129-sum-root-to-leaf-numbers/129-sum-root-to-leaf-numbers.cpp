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
  int sumNumbers(TreeNode *root)
  {
    return helper(root, 0);
  }
  int helper(TreeNode *node, int curr)
  {
    if (!node)
      return 0;

    curr = curr * 10 + node->val;

    if (node->left == nullptr && node->right == nullptr)
    {
      return curr;
    }

    int left = helper(node->left, curr);

    int right = helper(node->right, curr);
    return right + left;
  }
};