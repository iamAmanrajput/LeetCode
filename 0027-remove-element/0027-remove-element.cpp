class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int i = 0;
        int end = nums.size() - 1;
        int count = 0;

        while(i <= end){
            if(nums[i] == val){
                swap(nums[i],nums[end]);
                end --;
            }else{
                i++;
                count ++;
            }
        }

        return count;

    }
};