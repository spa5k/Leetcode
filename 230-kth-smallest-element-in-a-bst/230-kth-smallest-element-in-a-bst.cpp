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
  vector<int> res;
  int kthSmallest(TreeNode *root, int k)
  {
    helper(root);
    return res[k - 1];
  }
  void helper(TreeNode *root)
  {
    if (root == nullptr)
    {
      return;
    }
    if (root->left)
    {

      helper(root->left);
    }
    res.push_back(root->val);
    if (root->right)
    {

      helper(root->right);
    }
  }
};