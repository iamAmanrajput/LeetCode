class Solution {
public:
    bool isGood(vector<int>& nums) {

        // Array sort karo
        sort(nums.begin(), nums.end());

        int n = nums.size();

        // Good array ka format:
        // [1,2,3,...,n-1,n-1]
        // Yaha maximum element = n-1 hona chahiye

        int maxElement = nums[n - 1];

        // Maximum element exactly n-1 hona chahiye
        if(maxElement != n - 1) {
            return false;
        }

        // 1 se n-2 tak elements exactly ek baar hone chahiye
        for(int i = 0; i < n - 1; i++) {

            if(nums[i] != i + 1) {
                return false;
            }
        }

        // Last element bhi maxElement ke equal hona chahiye
        if(nums[n - 1] != nums[n - 2]) {
            return false;
        }

        return true;
    }
};