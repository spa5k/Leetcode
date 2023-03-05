class Solution
{
public:
  int lengthOfLongestSubstring(string s)
  {
    unordered_set<char> letters;

    int first = 0;
    int second = 0;

    int result = 0;

    while (second < s.size())
    {
      if (letters.find(s[second]) == letters.end())
      {
        letters.insert(s[second]);
        result = max(result, second - first + 1);
        second++;
      }
      else
      {
        letters.erase(s[first]);
        first++;
      }
    }

    return result;
  }
};