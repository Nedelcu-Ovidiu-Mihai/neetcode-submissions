class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        //naive solution: O(n * n):
        // for each element in the vector check if there is another identical element in the array
        // for (int i = 0; i < nums.size() - 1; ++i)
        // {
        //     for (int j = i + 1; j < nums.size(); ++j)
        //     {
        //         if (nums[i] == nums[j])
        //         {
        //             return true;
        //         }        
        //     }
        // }
        // return false;

        // O(n * log(n)): sort then compare
        // std::sort(nums.begin(), nums.end());
        // for (int i = 0; i < nums.size() - 1; ++i)
        // {
        //     if (nums[i] == nums[i + 1])
        //     {
        //         return true;
        //     }
        // }
        
        // return false;

        std::unordered_set<int> table;
        for (int i = 0; i < nums.size(); ++i)
        {
            auto isDuplicate = table.contains(nums[i]);
            if (isDuplicate)
            {
                return true;
            }

            table.insert(nums[i]);
        }
        return false;

    }
};