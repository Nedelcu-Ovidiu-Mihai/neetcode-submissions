class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        // Time complexity: The input array is parsed a single time to build the stack: O(N)
        // Space complexity: a new stack of N size is required: O(N)
        std::vector<int> result(temperatures.size(), 0);
        std::stack<std::pair<int,int>> stack_of_temperatures;

        // 24, 23, 22, 21 -> 
        for (int i = 0; i < temperatures.size(); i++) {

            while(!stack_of_temperatures.empty() &&
                   stack_of_temperatures.top().first < temperatures[i]) {
                        
                const int idx = stack_of_temperatures.top().second;
                const int days_until_warmer = i - idx;
                result[idx] = days_until_warmer;
                stack_of_temperatures.pop();
            }
            
            stack_of_temperatures.push({temperatures[i], i});
        }

        // while(!stack_of_temperatures.empty()) {
        //     const int idx = stack_of_temperatures.top().second;
        //     result[idx] = 0;
        //     stack_of_temperatures.pop();
        // }

        return result;
    }
};
