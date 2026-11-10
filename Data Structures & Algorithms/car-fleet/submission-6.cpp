class Solution {
    struct Info_t {
        int position;
        float time_to_dest;
    };
    
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
        
        vector<Info_t> position_and_time(position.size());
        for (int i = 0; i < position.size(); i++) {
            position_and_time[i].position = position[i];
            position_and_time[i].time_to_dest = time_to_destination[i];
        }

        std::sort(position_and_time.begin(), position_and_time.end(),
                 [] (Info_t left, Info_t right) {
                    return left.position < right.position;
                 });
        
        std::stack<Info_t> stack_of_positions(position_and_time.begin(), position_and_time.end());

        int counter = 0;
        float last_time_to_destination = -1; 
        while(!stack_of_positions.empty()) {
            auto top = stack_of_positions.top();
            stack_of_positions.pop();
            if (last_time_to_destination < top.time_to_dest) {
                counter++;
                last_time_to_destination = top.time_to_dest;
            }

        }
        return counter;
    }
};
