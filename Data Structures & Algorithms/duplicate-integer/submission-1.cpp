class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> set{};
        for (auto const& current : nums)
        {
            if (set.find(current) != set.end())
            {
                return true;
            }

            set.insert(current);
        }

        return false;
    }
};
