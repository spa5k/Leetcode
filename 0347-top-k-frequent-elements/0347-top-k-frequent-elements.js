class Solution
{
public:
  vector<int> topKFrequent(vector<int> &nums, int k)
  {
    vector<int> res{};
    priority_queue<pair<int, int>> pq{};
    unordered_map<int, int> mp{};
    for (auto &&num : nums)
    {
      mp[num]++;
    }
    for (auto &&i : mp)
    {
      pq.push({i.second, i.first});
    }
    for (int i = 0; i < k; i++)
    {
      res.push_back(pq.top().second);
      pq.pop();
    }
    return res;
  }
};