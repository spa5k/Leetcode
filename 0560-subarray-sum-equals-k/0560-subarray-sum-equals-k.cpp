class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> map;

        int sum = 0;
        int res = 0;
        map[sum] = 1;
        for (auto &&n : nums)
        {
            sum += n;
            res += map[sum - k];
            map[sum]++;
        }
        return res;
    }
};