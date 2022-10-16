class Solution
{
public:
  vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges)
  {
    set<int> left;
    for (auto &&group : edges)
    {
      int l = group[0];
      int r = group[1];
      left.insert(l);
    }
    for (auto &&group : edges)
    {

      int r = group[1];
      left.erase(r);
    }

    vector<int> res;
    for (auto &str : left)
    {
      res.push_back(str);
    }
    return res;
  }
};