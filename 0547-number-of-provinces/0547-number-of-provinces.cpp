class Solution
{
  int n;
  void dfs(int i, vector<vector<int>> &isConnected, vector<bool> &vis)
  {
    vis[i] = true;

    for (int j = 0; j < n; j++)
    {
      if (isConnected[i][j] == 1 && vis[j] == 0)
        dfs(j, isConnected, vis);
    }
  }

public:
  int findCircleNum(vector<vector<int>> &isConnected)
  {
    n = isConnected.size();

    int ans = 0;
    vector<bool> vis(n, false);
    for (int i = 0; i < n; i++)
    {
      if (vis[i] == false)
      {
        dfs(i, isConnected, vis);
        ans++;
      }
    }

    return ans;
  }
};