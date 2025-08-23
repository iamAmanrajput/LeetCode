class Solution {
public:
    int lengthOfLastWord(string s) {
        int end = s.size() - 1;

        while (end >= 0 && s[end] == ' ') {
            end--;
        }

        int ans = 0;
        // Count length of last word
        while (end >= 0 && s[end] != ' ') {
            ans++;
            end--;
        }
        return ans;
    }
};
