class Solution {
public:
    int characterReplacement(string s, int k) {
        int spare_chars = k;
        int max_freq = 0;
        // XXYYYZZ   k = 1
        // AABBCB k = 2
        // CCDABCCC k = 1

        unordered_map<char, int> char_freq;

        for (int start_idx = 0, end_idx = 0; end_idx < s.size(); end_idx++) {
            char_freq[s[end_idx]]++;
            max_freq = std::max(max_freq, char_freq[s[end_idx]]);

            if ((end_idx - start_idx + 1) - max_freq > k) {
                char_freq[s[start_idx]]--;
                start_idx++;

            }
        }

        return std::min(static_cast<int>(s.size()), max_freq + k);
    }
};
