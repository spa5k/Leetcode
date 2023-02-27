class Solution
{
public:
  bool isAnagram(string s, string t)
  {
    unordered_map<char, int> mp{};
    if (s.size() != t.size())
    {
      return false;
    }
    for (auto &&key : s)
    {
      mp[key]++;
    }
    for (auto &&key : t)
    {
      mp[key]--;
      if (mp[key] < 0)
        return false;
    }

    return true;
  }
};