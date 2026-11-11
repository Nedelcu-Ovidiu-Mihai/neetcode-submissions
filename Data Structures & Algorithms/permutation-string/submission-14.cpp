class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if (s1.size() > s2.size()) {
            return false;
        }

        // Time complexity: O(N)
        // Space complexity: O(N)
        // s1: abcdef
        // s2: dkfjdlkjfdlkjflkdjfcba
        std::unordered_map<char, int> char_freq_s1;
        for (char c : s1) {
            char_freq_s1[c]++;
        }

        std::unordered_map<char,int> char_freq_sub;
        for (int j = 0; j < s1.size(); j++) {
            char_freq_sub[s2[j]]++;
        }

        for (int i = 0; i < static_cast<int>(s2.size()) - static_cast<int>(s1.size()); i++) {
  
            if (char_freq_s1 == char_freq_sub) {
                return true;
            }

            char to_remove = s2[i];

            char_freq_sub[to_remove]--;
            if (char_freq_sub[to_remove] == 0) {
                char_freq_sub.erase(to_remove);
            } 

            //if (i + s1.size() < s2.size())
            char to_add = s2[i + s1.size()];
            char_freq_sub[to_add]++;
        }
        
         if (char_freq_s1 == char_freq_sub) {
            return true;
        }

        return false;    
    }
};
