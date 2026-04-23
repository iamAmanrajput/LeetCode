class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;
        // initial state
        ans.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > ans.back()) {
                ans.push_back(nums[i]);
            } else {
                // just bada number exist karta hai
                int index =
                    lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                // replace
                ans[index] = nums[i];
            }
        }

        return ans.size();
    }
};