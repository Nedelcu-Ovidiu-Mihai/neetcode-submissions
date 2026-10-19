class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //early return

        int max_length = 0;
        unordered_set<int> unique_numbers(nums.begin(), nums.end());
 
        for (int num : unique_numbers)
        {
            if (unique_numbers.find(num - 1) == unique_numbers.end())
            {
                int length = 1;
                while (unique_numbers.find(num + length) != unique_numbers.end())
                {
                    length++;      
                }
                max_length = std::max(max_length, length); 
            }
        }

        return max_length;
    }
};
