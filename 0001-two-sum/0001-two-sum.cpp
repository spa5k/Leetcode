class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            int curr = nums[i];
            int needed = target - curr;

            if (map.find(needed) != map.end())
            {
                return {i, map[needed]};
            }
            map[curr] = i;
        }
        return {};
    }
};