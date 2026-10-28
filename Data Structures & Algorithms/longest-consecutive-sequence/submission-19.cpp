class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        // if (nums.empty() == true) {
        //     return 0;
        // }

        // std::sort(nums.begin(), nums.end(), std::less<int>());
        // int temp_counter = 1;
        // int max_counter = 1;

        // for (int i = 0; i < (int)nums.size() - 1; ++i) {

        //     if (nums[i] == nums[i +1]) {
        //         continue;
        //     }

        //     if ((nums[i + 1] - nums[i]) == 1) {
        //         temp_counter++;
        //         max_counter = std::max(max_counter, temp_counter);
        //     }
        //     else {
        //         temp_counter = 1;
        //     }
        // }

        // return max_counter;

        // if (nums.empty()) {
        //     return 0;
        // }

        // std::unordered_set<int> set;
        // for (int num : nums) {
        //     set.insert(num);
        // }

        // int max_counter = 1;
        // for (int num : nums) {
        //     int temp_num = num;
        //     int temp_counter = 1;
        //     while (set.contains(temp_num + 1)) {
        //         temp_counter++;
        //         temp_num++;
        //     }

        //     max_counter = std::max(max_counter, temp_counter); 
        // }

        // return max_counter;

        // smartest approach: figure out the numbers that are at the beginning of a consecutive sequence
        // how ? -> check if num[i] - 1 does not exist -> if it does not exist -> num[i] is the starting point of a consecutive sequence

        // Time complexity: O(n)
        // Space complexity: O(n)

        if (nums.empty()) {
            return 0;
        }

        unordered_set<int> unique_nums;
        for (int num : nums) {
            unique_nums.insert(num);
        }

        int max_counter = 1;

        for (auto num : unique_nums) {
            if (!unique_nums.contains(num - 1)) {
                int temp_counter = 1;
                while(unique_nums.contains(++num)) {
                    temp_counter++;
                    max_counter = std::max(temp_counter, max_counter);
                }
            }
        }

        return max_counter;
    }
};
