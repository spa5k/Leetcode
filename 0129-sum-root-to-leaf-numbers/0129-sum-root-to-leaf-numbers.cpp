class Solution
{
public:
  int res = 0;

public:
  int sumNumbers(TreeNode *root)
  {
    helper(root, res);
    return res;
  }
  void helper(TreeNode *node, int curr)
  {
    if (!node)
    {
      return;
    }
    curr = node->val + curr * 10;
    if (!node->left && !node->right)
    {
      res += curr;
      return;
    }
    helper(node->right, curr);
    helper(node->left, curr);
  }
};