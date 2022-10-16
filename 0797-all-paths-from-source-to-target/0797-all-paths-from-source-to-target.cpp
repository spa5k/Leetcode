class Solution
{
public:
  int target;
  vector<vector<int>> res;
  vector<int> temp;
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
  {
    target = graph.size() - 1;
    dfs(graph);
    return res;
  }
  void dfs(vector<vector<int>> &graph, int currentNode = 0)
  {
    temp.push_back(currentNode);
    if (currentNode == target)
    {
      res.push_back(temp);
    }
    else
    {
      for (int node : graph[currentNode])
      {
        dfs(graph, node);
      }
    }
    temp.pop_back();
  }
};