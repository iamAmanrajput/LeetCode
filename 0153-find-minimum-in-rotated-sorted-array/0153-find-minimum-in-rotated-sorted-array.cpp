class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;

        if (nums[start] <= nums[end]) {
            return nums[start];
        }

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (mid - 1 >= 0 && nums[mid] < nums[mid - 1]) {
                return nums[mid];
            }

            if (mid + 1 < nums.size() && nums[mid] > nums[mid + 1]) {
                return nums[mid + 1];
            }

            if (nums[0] > nums[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return -1;
    }
};