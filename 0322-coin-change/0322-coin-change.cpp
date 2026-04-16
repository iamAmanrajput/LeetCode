class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        // Step 1: DP array initialize with INT_MAX
        vector<int> dp(amount + 1, INT_MAX);

        // Step 2: Base case
        dp[0] = 0;

        // Step 3: Build answer from 1 → amount
        for (int value = 1; value <= amount; value++) {

            int mini = INT_MAX; // maintain minimum for current value

            for (int i = 0; i < coins.size(); i++) {

                // Check valid and avoid overflow
                if (value - coins[i] >= 0 && dp[value - coins[i]] != INT_MAX) {

                    int ans = 1 + dp[value - coins[i]];
                    mini = min(mini, ans);
                }
            }

            // Store result in dp
            dp[value] = mini;
        }

        // If not possible
        if (dp[amount] == INT_MAX) {
            return -1;
        }

        return dp[amount];
    }
};