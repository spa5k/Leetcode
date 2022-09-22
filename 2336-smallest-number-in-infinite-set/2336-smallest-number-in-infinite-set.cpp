class SmallestInfiniteSet
{
public:
  priority_queue<int, vector<int>, greater<int>> pq;
  vector<bool> is_present;
  SmallestInfiniteSet()
  {
    int i = 1;
    while (i <= 1000)
    {
      pq.push(i);
      i++;
    }
    is_present = vector<bool>(1000, true);
  }

  int popSmallest()
  {
    int t = pq.top();
    pq.pop();
    is_present[t] = false;
    return t;
  }

  void addBack(int num)
  {
    if (!is_present[num])
    {
      pq.push(num);
      is_present[num] = true;
    };
    return;
  }
};
/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */