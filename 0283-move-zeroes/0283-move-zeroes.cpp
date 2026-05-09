class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0; // Pointer to place the next non-zero element
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                // Swap current element with the element at index j
                swap(nums[i], nums[j]);

                j++; // Move j to the next index for placing non-zero
            }
        }
    }
};