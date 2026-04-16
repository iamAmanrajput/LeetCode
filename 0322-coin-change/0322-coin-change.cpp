class Solution {
public:
    int solve(vector<int>& coins, int amount, vector<int>& dp) {

        // Base case
        if (amount == 0) {
            return 0;
        }

        // If amount becomes negative → invalid
        if (amount < 0) {
            return INT_MAX;
        }

        // if ans already exist
        if (dp[amount] != -1) {
            return dp[amount];
        }

        int mini = INT_MAX;

        for (int i = 0; i < coins.size(); i++) {

            // recursive call
            int recAns = solve(coins, amount - coins[i], dp);

            // only update if valid answer
            if (recAns != INT_MAX) {
                int ans = 1 + recAns;
                mini = min(mini, ans);
            }
        }
        dp[amount] = mini;
        return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {

        int n = amount;
        vector<int> dp(n + 1, -1);

        int ans = solve(coins, amount, dp);

        // If no solution found
        if (ans == INT_MAX) {
            return -1;
        }

        return ans;
    }
};