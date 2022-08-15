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
  bool checkTree(TreeNode *root)
  {
    int val_root = root->val;
    int val_left = root->left->val;
    int val_right = root->right->val;

    if (val_root == val_left + val_right)
    {
      return true;
    }
    return false;
  }
};