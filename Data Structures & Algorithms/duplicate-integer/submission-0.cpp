class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_map<int, bool> map{};
        for (auto const& current : nums)
        {
            if (map.count(current))
            {
                return true;
            }

            map.insert({current, true});
        }

        return false;
    }
};
