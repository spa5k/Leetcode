class Solution
{
public:
  bool checkIfPangram(string sentence)
  {
    vector<bool> freq(26, false);

    for (auto ch : sentence)
      freq[ch - 'a'] = true;

    for (auto it : freq)
    {
      if (it == false)
        return false;
    }
    return true;
  }
};