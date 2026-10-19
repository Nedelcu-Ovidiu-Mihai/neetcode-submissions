class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequency_of_numbers = {};
        for (const int num : nums)
        {
            frequency_of_numbers[num]++;
        }

        map<int, vector<int>> ordered_frequency_of_nums = {};
        for (const auto& pair : frequency_of_numbers)
        {
            ordered_frequency_of_nums[pair.second].push_back(pair.first);
        }

        vector<int> result;
        int counter = 0;
        for (auto it = ordered_frequency_of_nums.rbegin(); it != ordered_frequency_of_nums.rend(); it++)
        {
            for (auto const el : it->second)
            {
                result.push_back(el);
                counter++;
                if (counter == k)
                {
                    return result;
                }
            }
        }

        return result;

    }
};
