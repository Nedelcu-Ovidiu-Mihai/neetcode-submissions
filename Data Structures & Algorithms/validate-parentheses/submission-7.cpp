class Solution {
public:
    bool isValid(string s) {
        std::stack<char> brackets;

        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                brackets.push(c);
            }
            else { // c == ')' || c == ']' || c == '}'
                if (!brackets.empty()) {
                    char top = brackets.top();
                    if (top == '(' && c != ')') {
                        return false;
                    }
                    else if (top == '[' && c != ']') {
                        return false;
                    }
                    else if (top == '{' && c != '}') {
                        return false;
                    }
                    
                    brackets.pop();
                }
                else {
                    return false;
                }
            }
        }
        bool is_empty = brackets.empty();
        return is_empty;
    }
};
