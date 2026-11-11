class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int max_length = 0;
        // xyzzabcd
        std::unordered_set<char> unique_chars;
        for (int end_idx, start_idx = 0; end_idx < s.size(); end_idx++) {
            if (!unique_chars.contains(s[end_idx])) {
                max_length = std::max(max_length, (end_idx - start_idx + 1));
            }
            else { // we have a duplicate char
                while(unique_chars.contains(s[end_idx])) {
                    unique_chars.erase(s[start_idx]);
                    start_idx++;
                }
            }
            unique_chars.insert(s[end_idx]);
        }
        return max_length;
    }
};
