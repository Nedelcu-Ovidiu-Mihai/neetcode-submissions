class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // Time complexity: O(N * log(N))
        // Space complexity: O(N)
        // unordered_map<int, int> freq_table;
        // for (int num : nums) {
        //     freq_table[num]++;
        // }

        // map<int, vector<int>> freq_table_sorted;
        // for (const auto& bucket : freq_table) {
        //     freq_table_sorted[bucket.second].push_back(bucket.first);
        // }

        // vector<int> output;
        // int counter = 0;

        // for (auto it = freq_table_sorted.rbegin(); it !=freq_table_sorted.rend(); ++it) {
        //     for (auto el : it->second) {
        //         output.push_back(el);
        //         counter++;
        //         if (counter == k) {
        //             return output;
        //         }

        //     }
        // }

        // return output;


        unordered_map<int, int> freq_table;
        for (const int& num : nums) {
            freq_table[num]++;    
        }

        vector<std::pair<int, int>> list_of_freq;
        for (auto p : freq_table) {
            list_of_freq.push_back(std::make_pair(p.second, p.first));
        }

        std::sort(list_of_freq.begin(), list_of_freq.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first;
        });

        vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(list_of_freq.at(i).second);
        }

        return result;
    }
};
