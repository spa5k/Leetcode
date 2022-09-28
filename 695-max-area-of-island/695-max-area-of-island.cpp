class Solution
{
public:
  int maxAreaOfIsland(vector<vector<int>> &grid)
  {
    int area = 0;
    for (int i = 0; i < grid.size(); i++)
    {
      for (int j = 0; j < grid[0].size(); j++)
      {
        if (grid[i][j] == 1)
        {
          area = max(area, dfs(i, j, grid));
        }
      }
    }
    return area;
  }
  int dfs(int i, int j, vector<vector<int>> &grid)
  {
    int rows = grid.size();
    int cols = grid[0].size();

    if (i < 0 || i == rows || j < 0 || j == cols || grid[i][j] == 0)
    {
      return 0;
    }
    grid[i][j] = 0;

    return (1 + dfs(i + 1, j, grid) +
            dfs(i - 1, j, grid) +
            dfs(i, j + 1, grid) +
            dfs(i, j - 1, grid));
  }
};