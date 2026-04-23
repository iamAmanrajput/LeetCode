class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size() + 1,
                               vector<int>(nums.size() + 1, 0));

        for (int i = nums.size() - 1; i >= 0; i--) {
            for (int j = i - 1; j >= -1; j--) {

                int include = 0;
                if (j == -1 || nums[j] < nums[i]) {
                    include = 1 + dp[i + 1][i + 1];
                }
                int exclude = 0 + dp[i + 1][j + 1];

                dp[i][j + 1] = max(include, exclude);
            }
        }

        return dp[0][0];
    }
};