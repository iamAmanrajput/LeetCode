class Solution {
public:
    bool check(vector<int>& nums) {

        int count = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++) {

            // Agar current element next se bada hai
            if(nums[i] > nums[(i + 1) % n]) {
                count++;
            }
        }

        // 1 se zyada break aaye to invalid
        return count <= 1;
    }
};