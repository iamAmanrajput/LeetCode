class Solution {
public:
    int maxSumArrayHelper(vector<int>& nums, int start, int end) {
        if(start >= end){
            return nums[start];
        }
        int maxLeftBorderSum = INT_MIN, maxRightBorderSum = INT_MIN;
        int leftBorderSum =0, rightBorderSum=0;
        int mid = start + (end-start)/2;

        int maxLeftSum = maxSumArrayHelper(nums,start,mid);
        int maxRightSum =  maxSumArrayHelper(nums,mid+1,end);

        // max CrossBorder Sum
        for(int i =mid;i>=start;i--){
            leftBorderSum += nums[i];
            if(leftBorderSum >  maxLeftBorderSum){
                maxLeftBorderSum = leftBorderSum;
            }
        }

        for(int i =mid+1;i<=end;i++){
            rightBorderSum += nums[i];
            if(rightBorderSum >  maxRightBorderSum){
                maxRightBorderSum = rightBorderSum;
            }
        }

        int crossBorderSum = maxLeftBorderSum + maxRightBorderSum;
        return max(maxLeftSum,max(maxRightSum,crossBorderSum));

    }

    int maxSubArray(vector<int>& nums) {
        return maxSumArrayHelper(nums, 0, nums.size() - 1);
    }
};