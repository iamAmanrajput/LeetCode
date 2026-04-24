class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int index = 0;
        int totalSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            totalSum += nums[i];
        }

        if (totalSum & 1) {
            // odd cannot be partitioned
            return false;
        }

        int target = totalSum / 2;
        int currSum = 0;

        vector<vector<int>> dp(nums.size() + 2, vector<int>(target + 1, 0));

        for (int row = 0; row <= nums.size(); row++) {
            dp[row][target] = 1;
        }

        int n = nums.size();

        for (int idx = n - 1; idx >= 0; idx--) {
            for (int s = target; s >= 0; s--) {
                bool include = 0;
                if (s + nums[idx] <= target) {
                include = dp[idx + 1][s + nums[idx]];
                }

                bool exclude = dp[idx + 1][s];

                dp[idx][s] = (include || exclude);
            }
        }

        return dp[0][0];
    }
};