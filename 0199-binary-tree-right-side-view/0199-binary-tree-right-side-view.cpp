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
        vector<int> res{};
        if (root == nullptr)
        {
            return res;
        }
        queue<TreeNode *> q;
        q.push(root);

        while (q.size() > 0)
        {
            vector<int> newLevel{};

            int n = q.size();

            for (int i = 0; i < n; i++)
            {
                TreeNode *node = q.front();
                newLevel.push_back(node->val);
                q.pop();
                if (node->left)
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }
            }
            res.push_back(newLevel[newLevel.size() - 1]);
        }
        return res;
    }
};