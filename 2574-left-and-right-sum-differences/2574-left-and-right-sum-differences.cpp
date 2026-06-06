class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        if (nums.size() == 1) {
            return {0};
        }

        vector<int> leftSum(nums.size(), 0);
        vector<int> rightSum(nums.size(), 0);

        for (int i = 1; i < nums.size(); i++) {
            int currSum = leftSum[i - 1] + nums[i - 1];
            leftSum[i] = currSum;
        }

        for (int i = nums.size() - 2; i >= 0; i--) {
            int currSum = rightSum[i + 1] + nums[i + 1];
            rightSum[i] = currSum;
        }

        vector<int> ans;

        for (int i = 0; i < leftSum.size(); i++) {
            int currLS = leftSum[i];
            int currRS = rightSum[i];

            ans.push_back(abs(currLS - currRS));
        }

        return ans;
    }
};