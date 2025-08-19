class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        int majorityElem = nums[0];
        int maxCount = 0;

        for(auto &val : mp){
            if(val.second > maxCount){
                maxCount = val.second;
                majorityElem = val.first;
            }
        }
        return majorityElem;
    }
};
