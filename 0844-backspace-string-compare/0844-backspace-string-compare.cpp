class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        stack<char> s1;
        stack<char> s2;

        for (auto &&i : s)
        {
            if (i == '#')
            {
                if (s1.size() > 0)
                {
                    s1.pop();
                }
            }
            else
            {
                s1.push(i);
            }
        }

        for (auto &&i : t)
        {
            if (i == '#')
            {
                if (s2.size() > 0)
                {
                    s2.pop();
                }
            }
            else
            {
                s2.push(i);
            }
        }

        if (s1.size() != s2.size())
        {
            return false;
        }

        int index = 0;
        while (index < s1.size())
        {
            char t1 = s1.top();
            s1.pop();
            char t2 = s2.top();
            s2.pop();
            if (t1 != t2)
            {
                return false;
            }
        }
        return true;
    }
};