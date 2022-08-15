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
  long long int ans = LLONG_MAX;
  void findMin(TreeNode *root, int curr)
  {
    if (!root)
    {
      return;
    }
    if (root->val != curr && (ans > root->val))
    {
      ans = root->val;
    }
    if (ans <= root->val)
      return;
    findMin(root->left, curr);
    findMin(root->right, curr);
  }
  int findSecondMinimumValue(TreeNode *root)
  {
    findMin(root, root->val);
    if (ans == LLONG_MAX)
      return -1;
    return ans;
  }
};