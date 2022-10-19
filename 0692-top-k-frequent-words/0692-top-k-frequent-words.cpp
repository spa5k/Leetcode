class Solution
{
public:
  vector<string> topKFrequent(vector<string> &words, int k)
  {
    map<string, int> cnt;
    vector<pair<int, string>> candidates;
    vector<string> res;
    priority_queue<pair<int, string>> h;
    for (string &word : words)
      cnt[word]++;
    for (auto &p : cnt)
    {
      h.push({-p.second, p.first});
      if (h.size() > k)
        h.pop();
    }
    while (!h.empty())
    {
      candidates.push_back(h.top());
      h.pop();
    }
    sort(candidates.begin(), candidates.end());
    for (auto &p : candidates)
      res.push_back(p.second);
    return res;
  }
};