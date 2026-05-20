class Solution {
public:
    int solve(int n, vector<int>& dp) {

        // base case
        if (n == 0 || n == 1)
            return 1;

        // agar pehle se calculate hai
        if (dp[n] != -1)
            return dp[n];

        // recursion + store in dp
        dp[n] = solve(n - 1, dp) + solve(n - 2, dp);

        return dp[n];
    }

    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);

        return solve(n, dp);
    }
};