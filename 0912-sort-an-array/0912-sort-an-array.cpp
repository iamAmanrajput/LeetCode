class Solution {
public:
    void mergeInPlace(vector<int>& nums, int start, int mid, int end) {
        int total_len = end - start + 1;
        int gap = total_len / 2 + total_len % 2; // ceil

        while (gap > 0) {
            int i = start, j = start + gap;
            while (j <= end) {
                if (nums[i] > nums[j]) {
                    swap(nums[i], nums[j]);
                }
                i++;
                j++;
            }
            gap = gap <= 1 ? 0 : (gap / 2) + (gap % 2);
        }
    }

    void mergeSort(vector<int>& nums, int start, int end) {
        if (start >= end) {
            return;
        }

        int mid = start + (end - start) / 2;

        mergeSort(nums, start, mid);
        mergeSort(nums, mid + 1, end);

        mergeInPlace(nums, start, mid, end);
    }

    vector<int> sortArray(vector<int>& nums) {

        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};