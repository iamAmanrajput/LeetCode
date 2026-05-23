class Solution {
public:
    int solve(int n, vector<int>& nums, vector<int>& dp) {
        if (n == 0) {
            return 0;
        }

        if (dp[n] != -1) {
            return dp[n];
        }

        int mini = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (n - nums[i] * nums[i] >= 0) {
                int ans = solve(n - nums[i] * nums[i], nums, dp);
                if (ans != INT_MAX) {
                    mini = min(mini, ans + 1);
                }
            }
        }

        return dp[n] = mini;
    }

    int numSquares(int n) {

        vector<int> nums;

        int i = 1;
        while (i * i <= n) {
            nums.push_back(i);
            i++;
        }

        vector<int> dp(n + 1, -1);

        return solve(n, nums, dp);
    }
};