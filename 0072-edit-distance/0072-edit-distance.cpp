class Solution {
public:
    int minDistance(string& a, string& b) {
        vector<vector<int>> dp(a.length() + 1, vector<int>(b.length() + 1, -1));

        for (int col = 0; col <= b.length(); col++) {
            dp[a.length()][col] = b.length() - col;
        }

        for (int row = 0; row <= a.length(); row++) {
            dp[row][b.length()] = a.length() - row;
        }

        for (int i = a.length() - 1; i >= 0; i--) {
            for (int j = b.length() - 1; j >= 0; j--) {
                int ans = 0;
                if (a[i] == b[j]) {
                    ans = 0 + dp[i + 1][j + 1];
                } else {
                    int replace = 1 + dp[i + 1][j + 1];
                    int insert = 1 + dp[i][j + 1];
                    int remove = 1 + dp[i + 1][j];

                    ans = min(insert, min(remove, replace));
                }
                dp[i][j] = ans;
            }
        }

        return dp[0][0];
    }
};