class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        // Time complexity: worst case scenario, only zeros -> O(n * n)
        // Space complexity: O(n)
        int product  = 1;
        for (const int& num : nums) {
            product *= num;
        }

        vector<int> result(nums.size(), 0);

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {

                int temp_product = 1;
                for (int j = 0; j < nums.size(); ++j) {
                    if (i != j)
                    {
                        temp_product *= nums[j];
                    }
                }
                result[i] = temp_product;

            }
            else {
                result[i] = (product / nums[i]);
            }

        }

        return result;
        
        // [ 2,  2,  2,  2,  2,  2] -> [32, 32, 32, 32, 32, 32]
        // [ 2,  4,  8, 16, 32, 64]
        // [64, 32, 16,  8,  4,  2]

        // [3,      4,   5,   7,   2,   1,    2]
        // [3,     12,  60, 420, 840, 840, 1680]
        // [1680, 560, 140,  28,   4,   2,    2]

        // [2, 2, 2, 0, 2, 2, 2] -> [0, 0, 0, 64, 0, 0, 0]
        // [2, 4, 8, 0, 0, 0, 0] 



    }
};
