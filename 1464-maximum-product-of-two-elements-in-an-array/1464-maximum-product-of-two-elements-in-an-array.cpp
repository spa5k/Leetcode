class Solution
{
public:
  int maxProduct(vector<int> &nums)
  {
    priority_queue<int> mh;
    for (auto curr : nums)
    {
      mh.push(curr);
    }
    int a = mh.top();
    mh.pop();
    int b = mh.top();
    return (a - 1) * (b - 1);
  }
};