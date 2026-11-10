class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        std::vector<int> result(temperatures.size(), 0);
        std::stack<std::pair<int,int>> stack_of_temperatures;

        // 24, 23, 22, 21 -> 
        for (int i = 0; i < temperatures.size(); i++) {

            while(!stack_of_temperatures.empty() &&
                   stack_of_temperatures.top().first < temperatures[i]) {
                        
                auto top_pair = stack_of_temperatures.top();
                int idx = top_pair.second;
                int days_until_warmer = i - idx;
                result[idx] = days_until_warmer;
                stack_of_temperatures.pop();
            }
            
            stack_of_temperatures.push({temperatures[i], i});
        }

        // while(!stack_of_temperatures.empty()) {
        //     int idx = stack_of_temperatures.top().second;
        //     result[idx] = 0;
        //     stack_of_temperatures.pop();
        // }

        return result;
    }
};
