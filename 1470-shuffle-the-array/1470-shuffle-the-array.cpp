class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int size = nums.size();
        int k = 0;
        vector<int> vect;
        for (int i = 0; i < size; i++) {
            if (i % 2 == 0) {
                vect.push_back(nums[k]);
                k++;
            } else {
                vect.push_back(nums[n]);
                n++;
            }
        }
        return vect;
    }
};