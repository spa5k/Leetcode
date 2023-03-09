class Solution
{
public:
  int numOfSubarrays(vector<int> &arr, int k, int threshold)
  {
    threshold *= k;
    int sum = 0;
    int count = 0;
    for (int i = 0; i < k; i++)
    {
      sum += arr[i];
    }
    if (sum >= threshold)
    {
      count++;
    }
    for (int i = k; i < arr.size(); i++)
    {
      sum += arr[i] - arr[i - k];
      if (sum >= threshold)
      {
        count++;
      }
    }
    return count;
  }
};