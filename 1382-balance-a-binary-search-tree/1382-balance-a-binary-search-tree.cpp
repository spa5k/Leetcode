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
  vector<TreeNode *> sorted;

public:
  TreeNode *balanceBST(TreeNode *root)
  {
    inorder(root);
    return createTree(0, sorted.size() - 1);
  }
  void inorder(TreeNode *root)
  {
    if (!root)
      return;
    inorder(root->left);
    sorted.push_back(root);
    inorder(root->right);
  }

  TreeNode *createTree(int start, int end)
  {
    if (start > end)
    {
      return nullptr;
    }
    int mid = (end - start) / 2 + start;
    TreeNode *node = sorted[mid];
    node->left = createTree(start, mid - 1);
    node->right = createTree(mid + 1, end);
    return node;
  }
};