class Solution {
public:
    bool check(vector<int>& nums, int i, int target, vector<vector<int>>& dp) {

        if (target == 0) return true;
        if (i >= nums.size()) return false;

        // already computed
        if (dp[i][target] != -1) {
            return dp[i][target];
        }

        bool include = false;
        if (target >= nums[i]) {
            include = check(nums, i + 1, target - nums[i], dp);
        }

        bool exclude = check(nums, i + 1, target, dp);

        return dp[i][target] = include || exclude;
    }

    bool canPartition(vector<int>& nums) {
        int totalSum = 0;

        for (int num : nums) {
            totalSum += num;
        }

        // odd check
        if (totalSum & 1) return false;

        int target = totalSum / 2;
        int n = nums.size();

        // dp init with -1
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return check(nums, 0, target, dp);
    }
};