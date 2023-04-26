class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        if (n == 0)
        {
            return false;
        }
        if (n == 1)
        {
            return true;
        }
        int recurse = isPowerOfThree(n / 3);
        bool reminder = n % 3 == 0;

        if (reminder && recurse)
        {
            return true;
        }
        return false;
    }
};