class Solution {
public:
    // Find the pivot point in the rotated sorted array
    int findPivot(vector<int>& arr) {
        int s = 0;
        int e = arr.size() - 1;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            // Check if mid is the pivot
            if (mid < e && arr[mid] > arr[mid + 1]) {
                return mid;
            }

            // Check if mid-1 is the pivot
            if (mid > s && arr[mid - 1] > arr[mid]) {
                return mid - 1;
            }

            // Adjust search range based on the pivot location
            if (arr[s] <= arr[mid]) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return -1; // If no pivot is found, the array is not rotated
    }

    // Standard binary search
    int binarySearch(vector<int>& arr, int s, int e, int target) {
        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (arr[mid] == target) {
                return mid; // Return the index if target is found
            }

            if (arr[mid] < target) {
                s = mid + 1; // Search right half
            } else {
                e = mid - 1; // Search left half
            }
        }
        return -1; // If target is not found
    }

    int search(vector<int>& nums, int target) {
        // Find the pivot index (index of the smallest element)
        int pivotIndex = findPivot(nums);
        
        // If no pivot found, the array is not rotated (regular sorted array)
        if (pivotIndex == -1) {
            return binarySearch(nums, 0, nums.size() - 1, target);
        }

        // If the target is in the range of the first sorted portion
        if (target >= nums[0] && target <= nums[pivotIndex]) {
            return binarySearch(nums, 0, pivotIndex, target);
        }
        // If the target is in the range of the second sorted portion
        return binarySearch(nums, pivotIndex + 1, nums.size() - 1, target);
    }
};
