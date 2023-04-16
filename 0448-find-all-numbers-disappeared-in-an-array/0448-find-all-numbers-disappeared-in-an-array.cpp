class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        vector<int> count(nums.size(), 0);

        for (int i = 0; i < nums.size(); i++)
        {
            int value = nums[i];
            count[value - 1] += 1;
        }

        vector<int> res;
        for (int i = 0; i < count.size(); i++)
        {
            int val = count[i];
            if (val == 0)
            {
                res.push_back(i + 1);
            }
        }

        return res;
    }
};