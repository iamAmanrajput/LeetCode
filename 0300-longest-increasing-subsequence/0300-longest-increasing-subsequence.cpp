class Solution {
public:
    int solve(vector<int>& nums, int curr, int prev, vector<vector<int>>& dp) {
        if (curr >= nums.size()) {
            return 0;
        };

        if (dp[curr][prev + 1] != -1) {
            return dp[curr][prev + 1];
        }

        int include = 0;
        if (prev == -1 || nums[prev] < nums[curr]) {
            include = 1 + solve(nums, curr + 1, curr, dp);
        }
        int exclude = 0 + solve(nums, curr + 1, prev, dp);

        dp[curr][prev + 1] = max(include, exclude);
        return dp[curr][prev + 1];
    };

    int lengthOfLIS(vector<int>& nums) {
        int curr = 0;
        int prev = -1;
        vector<vector<int>> dp(nums.size() + 1,
                               vector<int>(nums.size() + 1, -1));
        int ans = solve(nums, curr, prev, dp);
        return ans;
    }
};