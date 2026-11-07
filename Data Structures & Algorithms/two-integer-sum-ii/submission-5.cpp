#include <algorithm>
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        // [-9, -3, -1, 0, 1, 3, 6, 8, 9, 22]
        // select an element and do a binary search for the rest of the vector
        // Time complexity: O(NlogN)
        // Space complexity: O(N)
        // std::set nums_set(numbers.begin(), numbers.end());
        // for (auto it = nums_set.begin(); it != nums_set.end(); it++) {
            
        //     int complement = target - *it;
        //     if (auto it_second = nums_set.find(complement); it_second != nums_set.end()) {
        //         return {static_cast<int>(std::distance(nums_set.begin(), it) + 1),
        //                 static_cast<int>(std::distance(nums_set.begin(), it_second) + 1)};
        //     }
        // }

        // create an hash table: key - number, value - index
        // edge case: 2 numbers with same value -> store the last index
        // unordered_map<int, int> hash_table;
        // for (int i = 0; i < numbers.size(); i++) {
        //     hash_table[numbers[i]] = i;
        // }

        // for (int i = 0; i < numbers.size(); i++) {
        //     int complement = target - numbers[i];

        //     if (auto it = hash_table.find(complement); it != hash_table.end() && it->second != i) {
        //         return {i + 1, (it->second) + 1};
        //     }
        // }

        // return {};

        // two pointers approach
        // use the fact that the array is sorted
        // narrow down the interval until we find the target sum

        int left_idx = 0;
        int right_idx = numbers.size() - 1;

        while(left_idx < right_idx) {
            int temp_sum = numbers[left_idx] + numbers[right_idx];
            if (temp_sum == target) {
                return {left_idx + 1, right_idx + 1};
            }
            else if (temp_sum > target) {
                right_idx--;
            }
            else { // temp_sum < target
                left_idx++;
            }
        }

        return {};

    }
};
