class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;

        int i = 0;
        int j = n;

        while(nums.size() > j){
            ans.push_back(nums[i]);
            ans.push_back(nums[j]);
            i++;
            j++;
        }

        return ans;

        
    }
};