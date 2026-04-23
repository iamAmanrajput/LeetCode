class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>currRow(nums.size() + 1,0);
        vector<int>nextRow(nums.size() + 1,0);


        for (int i = nums.size() - 1; i >= 0; i--) {
            for (int j = i - 1; j >= -1; j--) {

                int include = 0;
                if (j == -1 || nums[j] < nums[i]) {
                    include = 1 + nextRow[i + 1];
                }
                int exclude = 0 + nextRow[j + 1];

                currRow[j + 1] = max(include, exclude);
            }
            nextRow = currRow;
        }

        return nextRow[0];
    }
};