class Solution
{
public:
  vector<int> maxSubsequence(vector<int> &a, int k)
  {
    priority_queue<pair<int, int>> pq;

    for (auto i = 0; i < a.size(); ++i)
    {
      pq.emplace(a[i], i);
    }

    vector<pair<int, int>> sorted;
    sorted.reserve(k);

    for (auto i = 0; i < k; ++i)
    {
      sorted.push_back(pq.top());
      pq.pop();
    }

    sort(sorted.begin(), sorted.end(), [](auto const &a, auto const &b)
         { return a.second < b.second; });

    vector<int> results;
    results.resize(k);

    transform(sorted.begin(), sorted.end(), results.begin(), [](auto const &x)
              { return x.first; });

    return results;
  }
};