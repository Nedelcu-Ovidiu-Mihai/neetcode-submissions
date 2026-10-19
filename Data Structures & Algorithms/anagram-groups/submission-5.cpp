class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        const int ALPHABET_SIZE = 26;
        unordered_map<string, vector<string>> anagram_group_table;
        for (const string& str : strs)
        {
            std::array<int, ALPHABET_SIZE> frequency_table = {0};
            for (const char letter : str)
            {
                frequency_table[letter - 'a']++;
            }

            string frequency_table_str = "";
            for(const int el : frequency_table)
            {
                frequency_table_str += "!" + std::to_string(el);
            }

            anagram_group_table[frequency_table_str].push_back(str);
        }


        vector<vector<string>> groups;
        for (const auto& group : anagram_group_table)
        {
            groups.push_back(group.second);
        }

        return groups;
        
    }
};
