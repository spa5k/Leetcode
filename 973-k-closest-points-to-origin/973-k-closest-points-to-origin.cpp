class Solution
{
public:
  vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
  {
    priority_queue<vector<int>> pq{};
    vector<vector<int>> res(k);
    for (auto &&point : points)
    {
      int x = point[0];
      int y = point[1];
      int dist = calculate(x, y);
      pq.push({dist, x, y});
      if (pq.size() > k)
      {
        pq.pop();
      }
    }
    for (int i = 0; i < k; i++)
    {
      vector<int> top = pq.top();
      pq.pop();
      res[i] = {top[1], top[2]};
    }
    return res;
  }
  int calculate(int x, int y)
  {
    return x * x + y * y;
  }
};