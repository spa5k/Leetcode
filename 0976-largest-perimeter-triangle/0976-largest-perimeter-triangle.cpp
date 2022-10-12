class Solution
{
public:
  int largestPerimeter(vector<int> &nums)
  {
    sort(nums.begin(), nums.end());
    for (int edges = nums.size() - 1; edges > 1; --edges)
    {
      int first = nums[edges];
      int second = nums[edges - 1];
      int third = nums[edges - 2];
      if (first < second + third)
        return first + second + third;
    }
    return 0;
  }
};