class Solution {
public:
    int solve(string& a, string& b, int i, int j, vector<vector<int>>& dp) {
        if (i == a.length()) {
            return b.length() - j;
        }

        if (j == b.length()) {
            return a.length() - i;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans = 0;
        if (a[i] == b[j]) {
            ans = 0 + solve(a, b, i + 1, j + 1, dp);
        } else {
            int replace = 1 + solve(a, b, i + 1, j + 1, dp);
            int insert = 1 + solve(a, b, i, j + 1, dp);
            int remove = 1 + solve(a, b, i + 1, j, dp);

            ans = min(insert, min(remove, replace));
        }

        dp[i][j] = ans;
        return dp[i][j];
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length() + 1,
                               vector<int>(word2.length() + 1, -1));
        int i = 0;
        int j = 0;
        int ans = solve(word1, word2, i, j, dp);
        return ans;
    }
};