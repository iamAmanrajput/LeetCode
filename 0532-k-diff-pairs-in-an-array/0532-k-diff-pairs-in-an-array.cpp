class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) {
            return 0;
        }

        // Array sort karo taaki Binary Search use kar sake
        sort(nums.begin(), nums.end());

        int count = 0;

        for (int i = 0; i < nums.size(); i++) {

            // Duplicate starting elements skip karo
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int target = nums[i] + k;

            // Binary Search in remaining array
            int s = i + 1;
            int e = nums.size() - 1;

            while (s <= e) {

                int mid = s + (e - s) / 2;

                // Pair found
                if (nums[mid] == target) {
                    count++;
                    break;
                }

                // Search right side
                if (nums[mid] < target) {
                    s = mid + 1;
                }
                // Search left side
                else {
                    e = mid - 1;
                }
            }
        }

        return count;
    }
};