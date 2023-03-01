class Solution
{
public:
  int longestConsecutive(vector<int> &nums)
  {
    unordered_set<int> s{nums.begin(), nums.end()};
    int longest = 0;
    for (auto &&num : nums)
    {
      if (!s.count(num - 1))
      {
        int length = 1;
        while (s.count(num + length))
        {
          ++length;
        }
        longest = max(length, longest);
      }
    }
    return longest;
  }
};