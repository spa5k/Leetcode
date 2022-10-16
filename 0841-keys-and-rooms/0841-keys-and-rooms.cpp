class Solution
{
public:
  void dfs(vector<vector<int>> &graph, int current, vector<bool> &visited)
  {
    visited[current] = true;
    for (int i = 0; i < graph[current].size(); i++)
    {
      if (!visited[graph[current][i]])
      {
        dfs(graph, graph[current][i], visited);
      }
    }
  }

  bool canVisitAllRooms(vector<vector<int>> &rooms)
  {
    int i, n = rooms.size();
    vector<bool> visited(n, false);
    dfs(rooms, 0, visited);
    for (i = 0; i < n; i++)
    {
      if (!visited[i])
      {
        return false;
      }
    }
    return true;
  }
};