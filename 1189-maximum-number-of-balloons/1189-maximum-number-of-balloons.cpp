class Solution
{
public:
    int maxNumberOfBalloons(string text)
    {
        int a = 0;
        int b = 0;
        int l = 0;
        int o = 0;
        int n = 0;

        for (auto &&i : text)
        {
            if (i == 'b')
                b++;
            if (i == 'a')
                a++;
            if (i == 'l')
                l++;
            if (i == 'o')
                o++;
            if (i == 'n')
                n++;
        }
        l /= 2;
        o /= 2;

        return min(b, min(a, min(l, min(o, n))));
    }
};