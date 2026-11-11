class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int start_row = 0;
        int end_row = matrix.size() - 1;

        const int COLS = matrix[start_row].size();

        while(start_row < end_row) {
            int mid_row = start_row + (end_row - start_row) / 2;

            if (matrix[mid_row][0] > target) {
                end_row = mid_row - 1;
            }
            else if (matrix[mid_row][COLS - 1] < target) {
                start_row = mid_row + 1;
            }
            else {
                start_row = mid_row;
                end_row = mid_row;
            }
        }

        int start_col = 0;
        int end_col = matrix[start_row].size() - 1;

        while (start_col <= end_col) {
            int mid_col = start_col + (end_col - start_col) / 2;

            if (matrix[start_row][mid_col] > target) {
                end_col = mid_col - 1;
            }
            else if (matrix[start_row][mid_col] < target) {
                start_col = mid_col + 1;
            }
            else { // matrix[start_row][mid_col] == target
                return true;
            }
        }

        return false;
    }
};
