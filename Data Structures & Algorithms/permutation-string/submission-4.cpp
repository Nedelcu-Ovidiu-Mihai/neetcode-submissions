class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        std::unordered_map<char, int> char_freq_s1;
        for (char c : s1) {
            char_freq_s1[c]++;
        }

        // 4, 5 ==> 0
        // abc
        // dkfjdlkjfdlkjflkdjfcba
        for (int i = 0; i <= static_cast<int>(s2.size()) - static_cast<int>(s1.size()); i++) {
            std::unordered_map<char,int> char_freq_s2;
            for (int j = i; j < i + s1.size(); j++) {
                char_freq_s2[s2[j]]++;
            }

            if (char_freq_s1 == char_freq_s2) {
                return true;
            }
        }
        return false;    
    }
};
