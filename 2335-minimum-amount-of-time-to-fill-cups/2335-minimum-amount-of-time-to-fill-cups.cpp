class Solution
{
public:
  int fillCups(vector<int> &arr)
  {
    priority_queue<int> pq;

    for (int i = 0; i < 3; i++)
    {
      if (arr[i])
        pq.push(arr[i]);
    }

    int ans = 0;

    while (pq.size() > 2)
    {
      int a = pq.top();
      pq.pop();
      int b = pq.top();
      pq.pop();

      if (--a)
        pq.push(a);
      if (--b)
        pq.push(b);

      ans++;
    }

    if (pq.size())
      ans += pq.top();

    return ans;
  }
};