typedef pair<int, int> pi;
class Solution
{
public:
  vector<int> maxSubsequence(vector<int> &nums, int k)
  {
    vector<int> ans;
    int n = nums.size();
    if (n == k)
      return nums;

    priority_queue<pi, vector<pi>, greater<pi>> pq;
    for (int i = 0; i < n; i++)
    { // sorting by value  (storing top k greater  value)
      pq.push({nums[i], i});
      if (pq.size() > k)
        pq.pop();
    }
    priority_queue<pi, vector<pi>, greater<pi>> sort;
    while (!pq.empty())
    { // sorting by index for subsequences
      sort.push({pq.top().second, pq.top().first});
      pq.pop();
    }
    while (!sort.empty())
    { // pushing in ans
      ans.push_back(sort.top().second);
      sort.pop();
    }

    return ans;
  }
};