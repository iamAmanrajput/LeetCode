class Solution {
public:
    void merge(vector<int>& nums, int s, int mid, int e, vector<int>& temp) {
        int i = s;
        int j = mid + 1;
        int k = s;

        while (i <= mid && j <= e) {
            if (nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
            }
        }

        while (i <= mid) {
            temp[k++] = nums[i++];
        }

        while (j <= e) {
            temp[k++] = nums[j++];
        }

        // copy back
        for (int idx = s; idx <= e; idx++) {
            nums[idx] = temp[idx];
        }
    }

    void mergeSort(vector<int>& nums, int s, int e, vector<int>& temp) {
        if (s >= e) return;

        int mid = s + (e - s) / 2;

        mergeSort(nums, s, mid, temp);
        mergeSort(nums, mid + 1, e, temp);

        merge(nums, s, mid, e, temp);
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> temp(n); // ek hi temp array bana rahe hain

        mergeSort(nums, 0, n - 1, temp);

        return nums;
    }
};