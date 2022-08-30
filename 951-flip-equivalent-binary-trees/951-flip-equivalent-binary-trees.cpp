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
  bool flipEquiv(TreeNode *root1, TreeNode *root2)
  {
    // If one is null, other should be null
    if (!root1 || !root2)
    {
      return !root1 && !root2;
    }
    // Roots must be equal
    if (root1->val != root2->val)
    {
      return false;
    }

    bool no_swap = (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right));
    bool swap = (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));
    return no_swap || swap;
  }
};