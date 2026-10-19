class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if (nums.size() == 0)
        {
            return 0;
        }

        std::sort(nums.begin(), nums.end());

        int length = 1;
        int max_length = length;

        const int CONSECUTIVE_DIFF = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            int diff = nums[i] - nums[i - 1];
            if (diff == CONSECUTIVE_DIFF)
            {
                length++;
                max_length = max(max_length, length);
                
            }
            else if (diff == 0)
            {
                continue;
            }
            else
            {
                
                length = 1; // reset the length;
            }
        }
        return max_length;
    }
};
