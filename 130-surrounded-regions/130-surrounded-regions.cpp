class Solution
{
public:
  void DFS(vector<vector<char>> &board, int i, int j)
  {
    int columns = board.size();
    int rows = board[0].size();

    if (i < 0 || j < 0 || i >= columns || j >= rows || board[i][j] != 'O')
      return;
    board[i][j] = '#';
    DFS(board, i - 1, j);
    DFS(board, i + 1, j);
    DFS(board, i, j - 1);
    DFS(board, i, j + 1);
  }

  void solve(vector<vector<char>> &board)
  {
    int columns = board.size();
    if (columns == 0)
    {
      return;
    }
    int rows = board[0].size();
    for (int i = 0; i < columns; i++)
    {
      if (board[i][0] == 'O')
      {
        DFS(board, i, 0);
      };
      if (board[i][rows - 1] == 'O')
      {
        DFS(board, i, rows - 1);
      }
    }

    for (int j = 0; j < rows; j++)
    {
      if (board[0][j] == 'O')
      {
        DFS(board, 0, j);
      }
      if (board[columns - 1][j] == 'O')
      {
        DFS(board, columns - 1, j);
      }
    }

    for (int i = 0; i < columns; i++)
      for (int j = 0; j < rows; j++)
      {
        if (board[i][j] == 'O')
          board[i][j] = 'X';
        if (board[i][j] == '#')
          board[i][j] = 'O';
      }
  }
};