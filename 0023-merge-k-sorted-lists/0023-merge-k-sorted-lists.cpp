typedef pair<int, ListNode *> node;
class Solution
{
public:
  ListNode *mergeKLists(vector<ListNode *> &lists)
  {
    priority_queue<node, vector<node>, greater<node>> pq;
    for (auto &&list : lists)
    {
      if (list)
      {
        pq.push({list->val, list});
      }
    }
    ListNode *head = NULL;
    ListNode *temp;
    while (!pq.empty())
    {
      auto p = pq.top();
      pq.pop();
      if (!head)
      {
        head = p.second;
      }
      else
      {
        temp->next = p.second;
      }
      temp = p.second;
      if(p.second->next) {
        pq.push({p.second->next->val, p.second->next});
      }
    }
    return head;
  }
};