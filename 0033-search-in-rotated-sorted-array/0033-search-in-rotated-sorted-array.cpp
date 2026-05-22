class Solution {
public:
    // Find pivot (largest element index)
    int findPivot(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            // Check if mid itself is pivot
            if (mid < e && nums[mid] > nums[mid + 1]) {
                return mid;
            }

            // Check if previous element is pivot
            if (mid > s && nums[mid - 1] > nums[mid]) {
                return mid - 1;
            }

            // Left part sorted -> pivot right me hoga
            if (nums[s] <= nums[mid]) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }

        return -1; // Array rotated nahi hai
    }

    // Normal binary search
    int binarySearch(vector<int>& nums, int s, int e, int target) {

        while (s <= e) {

            int mid = s + (e - s) / 2;

            if (nums[mid] == target)
                return mid;

            else if (nums[mid] < target)
                s = mid + 1;

            else
                e = mid - 1;
        }

        return -1; // target nahi mila
    }

    int search(vector<int>& nums, int target) {

        // Step 1: Find pivot index
        int pivot = findPivot(nums);

        // Agar pivot = -1
        // matlab array rotated nahi hai
        if (pivot == -1) {
            return binarySearch(nums, 0, nums.size() - 1, target);
        }

        // Step 2:
        // Check target first sorted half me hai ya nahi

        if (target >= nums[0] && target <= nums[pivot]) {

            // Search in first half
            return binarySearch(nums, 0, pivot, target);
        }

        // Otherwise search second half
        return binarySearch(nums, pivot + 1, nums.size() - 1, target);
    }
};