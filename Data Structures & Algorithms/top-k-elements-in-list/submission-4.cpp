class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq_table;
        for (int num : nums) {
            freq_table[num]++;
        }

        map<int, vector<int>> freq_table_sorted;
        for (const auto& bucket : freq_table) {
            freq_table_sorted[bucket.second].push_back(bucket.first);
        }

        vector<int> output;
        int counter = 0;

        for (auto it = freq_table_sorted.rbegin(); it !=freq_table_sorted.rend(); ++it) {
            for (auto el : it->second) {
                output.push_back(el);
                counter++;
                if (counter == k) {
                    return output;
                }

            }

        }

        return output;

    }
};
