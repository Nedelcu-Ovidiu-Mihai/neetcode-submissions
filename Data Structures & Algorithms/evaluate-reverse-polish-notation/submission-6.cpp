class Solution {
public:
     struct Operands_t {
        int l_operand;
        int r_operand;
        };

    int evalRPN(vector<string>& tokens) {
        for (auto& token : tokens) {
            if (token == "+") {
                auto operands = retrieve_operands();
                int result = operands.l_operand + operands.r_operand;
                m_tokens_stack.push(result);
            }
            else if (token == "-") {
                auto operands = retrieve_operands();
                int result = operands.l_operand - operands.r_operand;
                m_tokens_stack.push(result);
            }
            else if (token == "*") {
                auto operands = retrieve_operands();
                int result = operands.l_operand * operands.r_operand;
                m_tokens_stack.push(result);
            }
            else if (token == "/") {
                auto operands = retrieve_operands();
                int result = operands.l_operand / operands.r_operand;
                m_tokens_stack.push(result);
            }
            else { // we do not have an operator, we have a number
                m_tokens_stack.push(std::stoi(token));
            }
        }

        return m_tokens_stack.top();
        
    }

    Operands_t retrieve_operands() {
        Operands_t operands;
        operands.r_operand = m_tokens_stack.top();
        m_tokens_stack.pop();
        operands.l_operand = m_tokens_stack.top();
        m_tokens_stack.pop();
        return operands;
    }

    private:
        std::stack<int> m_tokens_stack;


};
