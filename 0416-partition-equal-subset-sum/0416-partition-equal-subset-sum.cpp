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

        vector<int> curr(target + 1, 0);
        vector<int> next(target + 1, 0);

        curr[target] = 1;
        next[target] = 1;


        int n = nums.size();

        for (int idx = n - 1; idx >= 0; idx--) {
            for (int s = target; s >= 0; s--) {
                bool include = 0;
                if (s + nums[idx] <= target) {
                include = next[s + nums[idx]];
                }

                bool exclude = next[s];

                curr[s] = (include || exclude);
            }
            next = curr;
        }

        return next[0];
    }
};