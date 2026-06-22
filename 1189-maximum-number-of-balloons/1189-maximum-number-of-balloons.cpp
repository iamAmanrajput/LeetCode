class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> freq(26, 0);

        // Count frequency of each character
        for (char ch : text) {
            freq[ch - 'a']++;
        }

        // 'l' and 'o' are needed twice
        return min({
            freq['b' - 'a'],
            freq['a' - 'a'],
            freq['l' - 'a'] / 2,
            freq['o' - 'a'] / 2,
            freq['n' - 'a']
        });
    }
};