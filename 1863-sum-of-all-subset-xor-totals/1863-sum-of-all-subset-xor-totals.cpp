class Solution
{
    void dfs(int start_index, vector<int> &nums, int currentXor, vector<int> &path, int &result)
    {
        if (start_index == nums.size())
        {
            result += currentXor;
            return;
        }
        // include current element in the subset
        path.push_back(nums[start_index]);
        dfs(start_index + 1, nums, currentXor ^ nums[start_index], path, result);
        path.pop_back();
        // exclude current element from the subset
        dfs(start_index + 1, nums, currentXor, path, result);
    }

public:
    int subsetXORSum(vector<int> &nums)
    {
        vector<int> path;
        int result = 0;
        dfs(0, nums, 0, path, result);
        return result;
    }
};