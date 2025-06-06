class Solution {
public:

void findSubsets(vector<int>& nums,int i,vector<vector<int>> &ans,vector<int> currAns){
    if(i >= nums.size()){
        ans.push_back(currAns);
        return;
    }

//exclude call
    findSubsets(nums,i+1,ans,currAns);

    // include call
    currAns.push_back(nums[i]);
    findSubsets(nums,i+1,ans,currAns);
}

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int i = 0;
        vector<int> currAns;
        findSubsets(nums, i, ans,currAns);
        return ans;
    }
};