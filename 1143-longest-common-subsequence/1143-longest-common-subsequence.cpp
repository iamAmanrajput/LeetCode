class Solution {
public:
    int longestCommonSubsequence(string& text1, string& text2) {
        vector<int> curr(text1.length() + 1, 0);
        vector<int> next(text1.length() + 1, 0);

        for (int j = text2.length() - 1; j >= 0; j--) {
            for (int i = text1.length() - 1; i >= 0; i--) {

                int ans = 0;
                if (text1[i] == text2[j]) {
                    ans = 1 + next[i + 1];
                } else {
                    ans = 0 + max(next[i], curr[i + 1]);
                }
                curr[i] = ans;
            }
            next = curr;
        }

        return next[0];
    }
};