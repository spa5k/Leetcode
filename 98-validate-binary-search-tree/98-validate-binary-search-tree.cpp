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
  bool isValidBST(TreeNode *root)
  {
    return isValid(root, nullptr, nullptr);
  }
  bool isValid(TreeNode *root, int *left, int *right)
  {
    if (root == nullptr)
    {
      return true;
    }
    if (right && root->val >= *right)
    {
      return false;
    }
    if (left && root->val <= *left)
    {
      return false;
    }
    bool l = isValid(root->left, left, &(root->val));
    bool r = isValid(root->right, &(root->val), right);
    return l && r;
  }
};