class Solution {
public:
    int maxArea(vector<int>& heights) {
        
        // [1, 7, 7, 0, 0, 3, 1, 1]
        // Time complexity: O(N^2)
        // Space complexity: O(1)
        // int max_area = 0;
        // for (int i = 0; i < heights.size() - 1; i++) {
        //     for (int j = i + 1; j < heights.size(); j++) {

        //         const int height = std::min(heights[i], heights[j]);
        //         const int width = j - i;
        //         int temp_area = height * width;
        //         max_area = std::max(max_area, temp_area);
        //     }
        // }
        // return max_area;

        // two pointers
        // compute a max based on the location of the pointers,
        // narrow down the interval at the side of the smallest pointer
        // continue until pointers meet
        // Time complexity: O(N)
        // Space complexity: O(1);
        int left_idx = 0;
        int right_idx = heights.size() - 1 ;
        int max_area = 0;

        // max_area = (right_idx - left_idx) * std::min(heights[left_idx], heights[right_idx]);
        while(left_idx < right_idx) {
            const int temp_area = std::min(heights[left_idx], heights[right_idx]) * (right_idx - left_idx);
            max_area = std::max(max_area, temp_area);

            if (heights[left_idx] > heights[right_idx]) {
                right_idx--;
            }
            else { // heights[left_idx] <= heights[right_idx]
                left_idx++;
            }
        }
        return max_area;
    }
};
