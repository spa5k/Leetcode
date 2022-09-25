class Solution
{
public:
  int DR[4] = {1, 0, -1, 0};
  int DC[4] = {0, -1, 0, 1};

  bool valid_index(int i, int j, vector<vector<char>> &grid)
  {
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
      return false;
    return true;
  }
  int numIslands(vector<vector<char>> &grid)
  {
    if (grid.size() == 0)
    {
      return 0;
    }
    int n = grid.size();
    int m = grid[0].size();
    int no_of_islands = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (grid[i][j] == '1')
        {
          no_of_islands++;
          bfs(i, j, grid);
        }
      }
    }
    return no_of_islands;
  }
  void bfs(int r, int c, vector<vector<char>> &grid)
  {
    grid[r][c] = '0';
    queue<pair<int, int>> q;
    q.push({r, c});
    while (!q.empty())
    {
      int i = q.front().first;
      int j = q.front().second;
      q.pop();
      for (int k = 0; k < 4; k++)
      {
        int ci = DR[k] + i;
        int cj = DC[k] + j;
        if (!valid_index(ci, cj, grid))
        {
          continue;
        }
        if (grid[ci][cj] == '1')
        {
          q.push({ci, cj});
          grid[ci][cj] = '0';
        }
      }
    }
  }
};