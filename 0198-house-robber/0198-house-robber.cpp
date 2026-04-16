class Solution {
public:
     int rob(vector<int>& nums) {

        int n = nums.size();

        // Edge case: if array is empty
        if (n == 0) return 0;

        // step 1: create dp array
        vector<int> dp(n, -1);

        // step 2: base case
        dp[n - 1] = nums[n - 1];

        // step 3: fill dp array from right to left
        for (int index = n - 2; index >= 0; index--) {

            int tempAns = 0;

            // safe check for index + 2
            if (index + 2 < n) {
                tempAns = dp[index + 2];
            }

            // include current house
            int include = nums[index] + tempAns;

            // exclude current house
            int exclude = 0 + dp[index + 1];

            // store maximum
            dp[index] = max(include, exclude);
        }

        // final answer
        return dp[0];
    }
};