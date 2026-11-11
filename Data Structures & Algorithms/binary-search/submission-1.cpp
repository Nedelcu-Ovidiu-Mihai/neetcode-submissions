class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left_idx = 0;
        int right_idx = nums.size() - 1;
        while(left_idx <= right_idx) {
            int mid_idx = left_idx + (right_idx - left_idx) / 2;

            if (nums[mid_idx] == target) 
            {
                return mid_idx;
            }
            else if (nums[mid_idx] > target) {
                right_idx = mid_idx - 1;
            }
            else { // nums[mid_idx] < target
                left_idx = mid_idx + 1;
            } 
        }

        return -1;
    }
};
