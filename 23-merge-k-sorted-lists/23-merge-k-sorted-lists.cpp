/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    ListNode *head = nullptr;
    ListNode *tmp;
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
        tmp->next = p.second;
      }
      tmp = p.second;
      if (p.second->next)
      {
        pq.push({p.second->next->val, p.second->next});
      }
    }
    return head;
  }
};