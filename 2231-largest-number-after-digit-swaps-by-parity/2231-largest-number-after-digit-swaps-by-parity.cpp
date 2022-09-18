class Solution
{
public:
  int largestInteger(int num)
  {
    string s = to_string(num);
    int n = s.size();

    priority_queue<int> even{};
    priority_queue<int> odd{};
    int result = 0;
    for (int i = 0; i < n; i++)
    {
      int temp = s[i] - '0';
      if (temp % 2)
      {
        odd.push(temp);
      }
      else
      {
        even.push(temp);
      }
    }

    for (int i = 0; i < n; i++)
    {
      result = result * 10;
      if ((s[i] - '0') % 2)
      {
        result += odd.top();
        odd.pop();
      }
      else
      {
        result += even.top();
        even.pop();
      }
    }
    return result;
  }
};