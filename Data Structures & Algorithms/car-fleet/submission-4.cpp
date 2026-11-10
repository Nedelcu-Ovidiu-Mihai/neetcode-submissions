class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<int> distance_travelled(position.size());
        for (int i = 0; i < position.size(); i++) {
            distance_travelled[i] = target - position[i];
        }

        vector<float> time_to_destination(position.size());
        for (int i = 0; i < position.size(); i++) {
            time_to_destination[i] = static_cast<float>(distance_travelled[i]) / speed[i];
        }

        // 2, 2, 2, 5, 5, 1, 0, 3, 2, 1
        
        vector<std::pair<int, float>> position_and_time(position.size());
        for (int i = 0; i < position.size(); i++) {
            position_and_time[i].first = position[i];
            position_and_time[i].second = time_to_destination[i];
        }

        std::sort(position_and_time.begin(), position_and_time.end(),
                 [] (std::pair<int, float> left, std::pair<int, float> right) {
                    return left.first < right.first;
                 });
        
        std::stack<std::pair<int, float>> stack_of_positions(position_and_time.begin(),
                                                           position_and_time.end());

        int counter = 0;
        float last_time_to_destination = -1; 
        while(!stack_of_positions.empty()) {
            auto top = stack_of_positions.top();
            stack_of_positions.pop();
            if (last_time_to_destination < top.second) {
                counter++;
                last_time_to_destination = top.second;
            }

        }
        return counter;
    }
};
