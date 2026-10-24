class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // naive solution: O(n*n) complexity
        // for (int i = 0; i < nums.size() - 1; ++i) {
        //     for (int j = i + 1; j < nums.size(); ++j) {

        //         if (nums[i] + nums[j] == target) {
        //             return vector<int> {i, j};
        //         }
        //     }
        // }

        // Space complexity: O(n)
        // Time complexity: O(n)
        std::unordered_map<int, int> lookup_table;
        for (int i = 0; i <  nums.size(); ++i) {
            int complementary_no = target - nums[i];

            auto it = lookup_table.find(complementary_no);
            if (it != lookup_table.end()) {
                int second_index = it->second;
                return vector<int> {second_index, i};
            }

            lookup_table[nums[i]] = i;  
        }
        // try an array approach ?
        // [3, 3, 5, 6, 7, 8, 9, 22, 33, -5, 5, 12, 13] | target: 19 
    }
};
