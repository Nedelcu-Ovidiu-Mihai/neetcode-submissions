class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if (nums.empty() == true) {
            return 0;
        }

        std::sort(nums.begin(), nums.end(), std::less<int>());
        int temp_counter = 1;
        int max_counter = 1;

        for (int i = 0; i < (int)nums.size() - 1; ++i) {

            if (nums[i] == nums[i +1]) {
                continue;
            }

            if ((nums[i + 1] - nums[i]) == 1) {
                temp_counter++;
                max_counter = std::max(max_counter, temp_counter);
            }
            else {
                temp_counter = 1;
            }
        }

        return max_counter; 
    }
};
