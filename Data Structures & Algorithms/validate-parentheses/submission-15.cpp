class Solution {
public:
    bool isValid(string s) {
        std::stack<char> brackets;
        // {[([](){})]}
        // for (char c : s) {
        //     if (c == '(' || c == '[' || c == '{') {
        //         brackets.push(c);
        //     }
        //     else { // c == ')' || c == ']' || c == '}'
        //         if (!brackets.empty()) {
        //             char top = brackets.top();
        //             if (top == '(' && c != ')') {
        //                 return false;
        //             }
        //             else if (top == '[' && c != ']') {
        //                 return false;
        //             }
        //             else if (top == '{' && c != '}') {
        //                 return false;
        //             }
                    
        //             brackets.pop();
        //         }
        //         else {
        //             return false;
        //         }
        //     }
        // }
        // bool is_empty = brackets.empty();
        // return is_empty;

        // create an hash table with brackets pairs

        std::unordered_map<char, char> mapping = {{'(', ')'}, {'[',']'}, {'{','}'}};

        for (char c : s) {
            if (mapping.contains(c)) {
                brackets.push(c);
            }
            // c == ')' || c == ']' || c == '}'
            else if (!brackets.empty() && c == mapping[brackets.top()]) { 
                brackets.pop();
            }
            else {
                return false;
            }
        }
        return brackets.empty();
    }
};
