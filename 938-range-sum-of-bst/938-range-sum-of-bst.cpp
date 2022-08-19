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
  int rangeSumBST(TreeNode *root, int low, int high)
  {
    if (root == nullptr)
    {
      return 0;
    }
    int val = 0;
    val = (root->val >= low && root->val <= high) ? root->val : 0;
    if (root->val < low)
    {
      val = val + rangeSumBST(root->right, low, high);
    }
    else if (root->val > high)
    {
      val = val + rangeSumBST(root->left, low, high);
    }
    else
    {
      val = val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    }
    root->left = root->right = nullptr;
    return val;
  }
};