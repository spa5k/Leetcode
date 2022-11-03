class Solution
{
public:
  int longestPalindrome(vector<string> &words)
  {
    unordered_map<string, int> map;
    int counter = 0;

    for (string w : words)
    {
      string rev = w;
      reverse(w.begin(), w.end());
      if (map[w])
      {
        map[w]--;
        counter += 4;
      }
      else
      {
        map[rev] += 1;
      }
    }
    vector<string> moreWords{};
    for (auto &&i : map)
    {
      string first = i.first;
      string rev = first;
      reverse(first.begin(), first.end());
      if (map[first] && rev == first)
      {
        moreWords.push_back(first);
      }
    }
    if (moreWords.size() > 0)
    {
      counter += 2;
    }

    return counter;
  }
};