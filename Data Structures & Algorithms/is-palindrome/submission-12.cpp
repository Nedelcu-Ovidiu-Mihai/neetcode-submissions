class Solution {
public:
    bool is_alpha_num(char c) {
        return ((c >= 'A' && c <= 'Z') ||
                (c >= 'a' && c <= 'z') ||
                (c >= '0' && c <= '9'));
    }

    char to_lower_case(char c) {
        const uint8_t diff = 'a' - 'A';
        return (c >= 'A' && c <= 'Z') ? c + diff : c;
    }

    bool isPalindrome(string s) {



        // vector<char> shrinked_s;
        // for (char c : s) {
        //     if (std::isalnum(c)) {
        //         shrinked_s.push_back(std::tolower(c));
        //     }
        // }


        // int half_size = shrinked_s.size() / 2;

        // std::vector<char> front_half;
        // std::vector<char> end_half;

        // for (int i = 0; i < half_size; ++i) {
        //     front_half.push_back(shrinked_s[i]);
        // }

        // for (int i = (int)(shrinked_s.size() - 1); i >= int(shrinked_s.size() - half_size); --i) {
        //     end_half.push_back(shrinked_s[i]);
        // }

        // for (int i = 0; i < half_size; ++i) {
        //     if (front_half[i] != end_half[i]) {
        //         return false;
        //     }
        // }
        // return true;

        // Time complexity: O(n)
        // Space complexity: O(n)
        vector<char> alphanum_s;
        for (char c : s) {
            if(is_alpha_num(c)) {
                alphanum_s.push_back(to_lower_case(c));
            }
        }

        int start_idx = 0;
        int end_idx = (int)alphanum_s.size() - 1;

        while (start_idx < end_idx) {

            if (alphanum_s[start_idx] != alphanum_s[end_idx]) {
                return false;
            }
            ++start_idx;
            --end_idx;
        }

        return true;

    }


};
