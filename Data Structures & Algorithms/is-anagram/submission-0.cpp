#include <string>
class Solution {
public:
    bool isAnagram(string s, string t) {
        // we need a table for each string
        // c - 3
        // b - 2
        // f - 1
        std::unordered_map<char, int> s_table;
        std::unordered_map<char, int> t_table;

        for (const char letter : s)
        {
            auto it = s_table.find(letter);
            if (it != s_table.end())
            {
                (it->second)++;
            }
            else
            {
                s_table.insert(std::make_pair(letter, 1));
            }
        }

        for (const char letter : t)
        {
             auto it = t_table.find(letter);
            if (it != t_table.end())
            {
                (it->second)++;
            }
            else
            {
                t_table.insert(std::make_pair(letter, 1));
            }           
        }

        if (s_table == t_table)
        {
            return true;
        }
        else
        {
            return false;
        }

    }
};
