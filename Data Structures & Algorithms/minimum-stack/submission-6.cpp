class MinStack {
public:
    MinStack() {
    }
    
    void push(int val) {
        m_data.push(val);

        int min;
        if (min_data.empty()) {
            min = val;
        }
        else {
            min = std::min(min_data.top(), val);
        }
        min_data.push(min);
    }
    
    void pop() {
        m_data.pop();
        min_data.pop();
    }
    
    int top() {
        return m_data.top();
    }
    
    int getMin() {
        return min_data.top();
    }
private:
    std::stack<int> m_data;
    std::stack<int> min_data;

};
