class Solution
{
public:
  vector<int> findAnagrams(string s, string p)
  {
    vector<int> sHash(26, 0);
    vector<int> pHash(26, 0);
    vector<int> res;

    if (p.size() > s.size())
      return res;

    int left = 0, right = 0;
    while (right < p.size())
    {
      pHash[p[right] - 'a']++;
      sHash[s[right] - 'a']++;
      right++;
    }
    right--;
    while (right < s.size())
    {
      if (pHash == sHash)
        res.push_back(left);
      right++;
      if (right != s.size())
      {
        sHash[s[right] - 'a']++;
        sHash[s[left] - 'a']--;
      }
      left++;
    }
    return res;
  }
};