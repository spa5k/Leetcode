class Solution
{
public:
  bool checkIfPangram(string sentence)
  {
    set<int> s;
    for (auto &letter : sentence)
    {
      s.insert(letter);
    }
    return s.size() == 26;
  }
};