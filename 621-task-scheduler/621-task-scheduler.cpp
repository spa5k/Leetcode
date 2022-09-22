class Solution
{
public:
  int leastInterval(vector<char> &tasks, int n)
  {
    if (n == 0)
      return tasks.size();
    unordered_map<char, int> m;
    for (auto ch : tasks)
    {

      m[ch]++; // adding the count of every character to the map
    }
    priority_queue<int> pq;
    for (auto x : m)
      pq.push(x.second);
    int cycles = 0;
    while (pq.empty() == false)
    {
      vector<int> temp;
      for (int i = 0; i <= n; i++) // running our process for the cooldown process
      {
        if (pq.empty() == false)
        {
          temp.push_back(pq.top()); // we are seeing the tasks that we are processing during this cooldown pweriod
          pq.pop();
        }
      }
      for (int i : temp)
      {
        if (--i > 0)
          pq.push(i);
      }
      cycles += (pq.empty() == true) ? temp.size() : n + 1;
    }

    return cycles;
  }
};