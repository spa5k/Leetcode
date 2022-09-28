class Solution
{
public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
  {
    int m = heights.size();
    int n = heights[0].size();
    vector<vector<bool>> pacific(m, vector<bool>(n));
    vector<vector<bool>> atlantic(m, vector<bool>(n));

    for (int i = 0; i < m; i++)
    {
      dfs(i, 0, heights, pacific);
      dfs(i, n - 1, heights, atlantic);
    }

    for (int j = 0; j < n; j++)
    {
      dfs(0, j, heights, pacific);
      dfs(m - 1, j, heights, atlantic);
    }

    vector<vector<int>> result;

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (pacific[i][j] && atlantic[i][j])
        {
          result.push_back({i, j});
        }
      }
    }

    return result;
  }
  void dfs(int i, int j, vector<vector<int>> &heights, vector<vector<bool>> &visited)
  {
    visited[i][j] = true;
    int m = heights.size();
    int n = heights[0].size();

    if (i > 0 && !visited[i - 1][j] && heights[i - 1][j] >= heights[i][j])
    {
      dfs(i - 1, j, heights, visited);
    }
    if (i < m - 1 && !visited[i + 1][j] && heights[i + 1][j] >= heights[i][j])
    {
      dfs(i + 1, j, heights, visited);
    }
    if (j > 0 && !visited[i][j - 1] && heights[i][j - 1] >= heights[i][j])
    {
      dfs(i, j - 1, heights, visited);
    }
    if (j < n - 1 && !visited[i][j + 1] && heights[i][j + 1] >= heights[i][j])
    {
      dfs(i, j + 1, heights, visited);
    }
  }
};