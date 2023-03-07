class Solution
{
public:
  bool containsNearbyDuplicate(vector<int> &nums, int k)
  {
    unordered_map<int, int> map;
    int i = 0, j = 0;
    for (; j < nums.size(); j++)
    {
      if (j > k)
      {
        map[nums[i++]]--;
      }
      if (map[nums[j]] > 0)
      {
        return true;
      }
      map[nums[j]]++;
    }
    return false;
  }
};