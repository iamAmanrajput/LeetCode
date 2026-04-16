class Solution {
public:
    int rob(vector<int>& nums) {

        int n = nums.size();

        // Edge case: if array is empty
        if (n == 0) return 0;

        // Edge case: if only one house
        if (n == 1) return nums[0];

        // prev → dp[index + 1]
        // next → dp[index + 2]
        int prev = nums[n - 1]; // last house
        int next = 0;           // beyond last (0)
        int curr = 0;

        // Traverse from right to left
        for (int index = n - 2; index >= 0; index--) {

            // Include current house
            // nums[index] + dp[index + 2]
            int include = nums[index] + next;

            // Exclude current house
            // dp[index + 1]
            int exclude = prev;

            // Take maximum
            curr = max(include, exclude);

            // Shift values for next iteration
            next = prev;
            prev = curr;
        }

        // Final answer stored in curr
        return curr;
    }
};