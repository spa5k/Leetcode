class Solution
{
public:
  vector<int> twoSum(vector<int> &nums, int target)
  {
    unordered_map<int, int> mp{};
    for (int i = 0; i < nums.size(); i++)
    {
      int element = nums[i];
      int n = target - element;
      if (mp.find(n) != mp.end())
      {
        return {mp[n], i};
      }
      mp[element] = i;
    }
    return {};
  }
};