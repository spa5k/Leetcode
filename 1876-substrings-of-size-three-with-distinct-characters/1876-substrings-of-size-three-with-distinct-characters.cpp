class Solution
{
public:
  int countGoodSubstrings(string s)
  {
    int res = 0;

    unordered_map<char, int> map{};
    for (int i = 0; i < s.size(); i++)
    {
      if (i > 2 and --map[s[i - 3]] == 0)
      {
        map.erase(s[i - 3]);
      }
      map[s[i]]++;
      if (map.size() == 3)
        res++;
    }
    return res;
  }
};