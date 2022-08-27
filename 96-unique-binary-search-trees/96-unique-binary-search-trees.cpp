class Solution
{
public:
  int dp[20]{};
  int numTrees(int n)
  {
    // numTrees[4] =  numTrees[0] * numTrees[3] +
    //                numTrees[1] * numTrees[2] +
    //                numTrees[2] * numTrees[1] +
    //                numTrees[3] * numTress[1]
    if (n <= 1)
      return 1;
    if (dp[n])
      return dp[n];
    for (int i = 1; i <= n; i++)
    {
      dp[n] += numTrees(i - 1) * numTrees(n - i);
    }
    return dp[n];
  }
};