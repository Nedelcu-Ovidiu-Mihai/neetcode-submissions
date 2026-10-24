class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        // Time complexity: worst case scenario, only zeros -> O(n * n)
        // Space complexity: O(n)
        // int product  = 1;
        // for (const int& num : nums) {
        //     product *= num;
        // }

        // vector<int> result(nums.size(), 0);

        // for (int i = 0; i < nums.size(); ++i) {
        //     if (nums[i] == 0) {

        //         int temp_product = 1;
        //         for (int j = 0; j < nums.size(); ++j) {
        //             if (i != j)
        //             {
        //                 temp_product *= nums[j];
        //             }
        //         }
        //         result[i] = temp_product;

        //     }
        //     else {
        //         result[i] = (product / nums[i]);
        //     }

        // }

        // return result;
        

        // [3,      4,   5,   7,   2,   1,    2]


        vector<int> pre_product(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i) {
            pre_product[i] = pre_product[i - 1] * nums[i - 1]; 
        }

        vector<int> post_product(nums.size(), 1);
        for (int i = nums.size() - 2; i >= 0; --i) {
            post_product[i] = post_product[i + 1] * nums[i + 1];
        }

        vector<int> result(nums.size());

        for (int i = 0; i < nums.size(); ++i) {
            result[i] = pre_product[i] * post_product[i];
        }
        
        return result;

    }
};
