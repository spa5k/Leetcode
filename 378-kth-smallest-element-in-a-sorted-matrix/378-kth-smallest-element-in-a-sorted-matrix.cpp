class Solution
{
public:
  int kthSmallest(vector<vector<int>> &matrix, int k)
  {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto &&mat : matrix)
    {
      for (auto &&i : mat)
      {
        pq.push(i);
      }
    }
    for (int i = 0; i < k - 1; i++)
    {
      pq.pop();
    }
    return pq.top();
  }
};