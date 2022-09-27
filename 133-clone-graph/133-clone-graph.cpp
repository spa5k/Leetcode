class Solution
{
public:
  Node *cloner(Node *cur, unordered_map<Node *, Node *> &mp)
  {
    if (mp.find(cur) != mp.end())
    {
      return mp[cur];
    }
    Node *clone = new Node(cur->val);
    mp[cur] = clone;
    for (auto &&nei : cur->neighbors)
    {
      clone->neighbors.push_back(cloner(nei, mp));
    }
    return clone;
  }
  Node *cloneGraph(Node *node)
  {
    unordered_map<Node *, Node *> mp;
    if (node == nullptr)
    {
      return nullptr;
    }
   if (node->neighbors.size() == 0)
    {
      Node *clone = new Node(node->val);
      return clone;
    }
    return cloner(node, mp);
  }
};