class Solution {
public:
    long long int MOD = 1000000007;

    int numRollsToTarget(int& n, int& k, int& target) {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                int ans = 0;
                for (int idx = 1; idx <= k; idx++) {
                    if (j - idx >= 0) {
                        ans = (ans + dp[i - 1][j - idx]) % MOD;
                    };
                }
                dp[i][j] = ans;
            }
        }

        return dp[n][target];
    }
};