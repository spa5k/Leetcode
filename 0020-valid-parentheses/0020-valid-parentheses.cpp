class Solution
{
public:
    bool isValid(string string)
    {
        stack<char> stack;

        if (string.size() == 0)
        {
            return true;
        }

        for (auto &&i : string)
        {
            if (i == '(' || i == '[' || i == '{')
            {
                stack.push(i);
            }
            else if ((i == ')' && !stack.empty() && stack.top() == '(') ||
                     (i == '}' && !stack.empty() && stack.top() == '{') ||
                     (i == ']' && !stack.empty() && stack.top() == '['))
            {
                stack.pop();
            }
            else
            {
                return false;
            }
        }
        if (stack.empty())
        {
            return true;
        }
        return false;
    }
};