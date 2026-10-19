class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> table;
        vector<int> pair_to_target;

        for (int i = 0; i < nums.size(); i++)
        {
            auto it = table.find(target - nums[i]);
            if (it == table.end())
            {
                table[nums[i]] = i;
            }
            else
            {
                pair_to_target.push_back(it->second);
                pair_to_target.push_back(i);
                return pair_to_target;
            }
        }
        // if no solution is found, return an empty vector
        return pair_to_target;
    }
};
