class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        if (nums[0] < nums.back()) {
            return nums[0];
        }

        int start = 0;
        int end = nums.size() - 1;
        int ans = 0;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (mid - 1 >= 0 && nums[mid - 1]) {
                ans = nums[mid];
            }

            if (mid + 1 < nums.size() && nums[mid] > nums[mid + 1]) {
                ans = nums[mid + 1];
            }

            if (nums[0] > nums[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return ans;
    }
};