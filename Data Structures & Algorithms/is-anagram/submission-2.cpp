class Solution {
public:
    bool isAnagram(string s, string t) {
        // Time complexity O(n + m)
        // Space complexity O(n + m)
        // std::unordered_map<char, int> s_freq_table;
        // std::unordered_map<char, int> t_freq_table;

        // for (char c : s)
        // {
        //     s_freq_table[c] = s_freq_table[c] + 1 ;
   
        // }

        // for (char c : t)
        // {
        //     t_freq_table[c] = t_freq_table[c] + 1 ;
        // }

        // if (s_freq_table == t_freq_table)
        // {
        //     return true;
        // }
        // else
        // {
        //     return false;
        // }

        // Time complexity: O(n + m);
        // Space complexity - constant -> 2 arrays of 26 elements each
        constexpr int ALPHABET_SIZE = 26;
        constexpr int ASCII_LOWER_CASE_A = 97;
        std::array<int, ALPHABET_SIZE> s_freq_table {};
        std::array<int, ALPHABET_SIZE> t_freq_table {};

        for (char c : s)
        {
            s_freq_table[c - ASCII_LOWER_CASE_A]++;
        }

        for (char c : t)
        {
            t_freq_table[c - ASCII_LOWER_CASE_A]++;
        }

        if (s_freq_table == t_freq_table)
        {
            return true;
        }
        else
        {
            return false;
        }

    }
};
