#include <unordered_map>
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_map<int, bool> unique_table;
        bool areDuplicates = false;
        for (int element : nums)
        {
            auto it = unique_table.find(element);
            if (it == unique_table.end())
            {
                unique_table.insert(std::make_pair(element, true));
            }
            else
            {
                areDuplicates = true;
                break;
            }
        }
        return areDuplicates;
    }
};
