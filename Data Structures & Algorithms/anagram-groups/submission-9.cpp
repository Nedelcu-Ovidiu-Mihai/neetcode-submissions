constexpr int ALPHABET_LENGTH = 26;

struct ArrayHash {
    std::size_t operator()(const std::array<char, ALPHABET_LENGTH>& arr) const {
        std::size_t hash_val = 0;
        for (char c : arr) {
            hash_val = hash_val * 31 + std::hash<char>{}(c);
        }

        return hash_val;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

      // hash table with key - value pairs, where key: freq_array and value: vector of string
      // convert the hash table into a vector, where each key is a new entry in the vector
      constexpr int LOWER_CASE_A_ASCII = static_cast<int>('a');
      std::unordered_map<std::array<char, ALPHABET_LENGTH>, std::vector<std::string>, ArrayHash> hash_table;

      for (const string& word : strs) {

        std::array<char, ALPHABET_LENGTH> freq_array {};

        for (char c : word) {
            freq_array[c - LOWER_CASE_A_ASCII]++;
        }

        hash_table[freq_array].push_back(word);
        
      }

      std::vector<vector<string>> output;

      for (const auto& p : hash_table) {
        output.push_back(p.second);
      }

      return output;  
    }
};
