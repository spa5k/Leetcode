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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        if (root == nullptr)
        {
            return res;
        }
        queue<TreeNode *> pq{};
        bool x = true;
        pq.push(root);

        while (pq.size() > 0)
        {
            int n = pq.size();
            vector<int> newLevel{};
            for (int i = 0; i < n; i++)
            {
                TreeNode *node = pq.front();
                pq.pop();
                newLevel.push_back(node->val);

                if (node->left)
                {
                    pq.push(node->left);
                }

                if (node->right)
                {
                    pq.push(node->right);
                }
            }
            if (!x)
            {
                reverse(newLevel.begin(), newLevel.end());
            }
            x = !x;
            res.push_back(newLevel);
        }
        return res;
    }
};