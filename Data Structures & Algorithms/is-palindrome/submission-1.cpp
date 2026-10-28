class Solution {
public:
    bool isPalindrome(string s) {

        vector<char> shrinked_s;
        for (char c : s) {
            if (std::isalnum(c)) {
                shrinked_s.push_back(std::tolower(c));
            }
        }     
        int half_size = shrinked_s.size() / 2;

        std::vector<char> front_half;
        std::vector<char> end_half;

        for (int i = 0; i < half_size; ++i) {
            front_half.push_back(shrinked_s[i]);
        }

        for (int i = shrinked_s.size() - 1; i >= half_size; --i) {
            end_half.push_back(shrinked_s[i]);
        }

        for (int i = 0; i < half_size; ++i) {
            if (front_half[i] != end_half[i]) {
                return false;
            }
        }

        return true;

    }
};
