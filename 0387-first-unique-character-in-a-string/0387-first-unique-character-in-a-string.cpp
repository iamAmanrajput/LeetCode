class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> map;

        // Count frequency of each character
        for (int i = 0; i < s.size(); i++) {
            map[s[i]]++;
        }

        // Find the first character with frequency 1
        for (int i = 0; i < s.size(); i++) {
            if (map[s[i]] == 1) {
                return i;
            }
        }

        return -1; // No unique character
    }
};
