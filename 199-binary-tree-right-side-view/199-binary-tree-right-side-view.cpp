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
  vector<int> rightSideView(TreeNode *root)
  {
    vector<int> res;
    helper(root, res, 0);
    return res;
  };
  void helper(TreeNode *root, vector<int> &res, int lvl)
  {
    if (!root)
      return;
    if (res.size() == lvl)
    {
      res.push_back(root->val);
    }
    helper(root->right, res, lvl + 1);
    helper(root->left, res, lvl + 1);
  };
};