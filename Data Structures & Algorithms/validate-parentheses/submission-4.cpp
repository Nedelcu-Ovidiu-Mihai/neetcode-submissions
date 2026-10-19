class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;
        for (char el : s)
        {
            if (el == '{' || el == '[' || el == '(')
            {
                brackets.push(el);
            }
            else if (!brackets.empty())
            {
                char top = brackets.top();
                if (el == '}')
                {
                    if (top == '{')
                    {
                        brackets.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (el == ']')
                {
                    if (top == '[')
                    {
                        brackets.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (el == ')')
                {
                    if (top == '(')
                    {
                        brackets.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            else // brackets empty and we have )]}
            {
                return false;
            }
        }

        bool valid = brackets.empty();
        return valid;
    }
};
