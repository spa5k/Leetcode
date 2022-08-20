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
  TreeNode *searchBST(TreeNode *root, int val)
  {
    if (!root)
    {
      return nullptr;
    }
    TreeNode *node = new TreeNode();
    if (val < root->val)
    {
      // Left subtree
      node = searchBST(root->left, val);
    }
    else if (val > root->val)
    {
      // go right
      node = searchBST(root->right, val);
    }
    else
    {
      node = root;
    }
    return node;
  }
};