class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {
    int left = 0;
    int right = 1;
    int maxProfit = 0;
    for (int i = 0; i < prices.size() - 1; i++)
    {
      int current_left = prices[left];
      int current_right = prices[right];
      int currentProfit = current_right - current_left;
      if (current_left > current_right)
      {
        left = right;
        right += 1;
        continue;
      }
      maxProfit = max(currentProfit, maxProfit);
      right += 1;
    }
    return maxProfit;
  }
};