class Solution
{
public:
  vector<int> twoSum(vector<int> &numbers, int target)
  {
    int left = 0;
    int right = numbers.size() - 1;
    while (left < right)
    {
      int l = numbers[left];
      int r = numbers[right];

      if (l + r == target)
      {
        return {left + 1, right + 1};
      }
      if (l + r > target)
      {
        right--;
        continue;
      }
      if (l + r < target)
      {
        left++;
      }
    };
    return {};
  }
};