class Solution {
public:
    int findKthLargest(vector<int>& nums, int& k) {
         priority_queue<int, vector<int>, greater<int>> pq;
        
        // insert initial k array of elements
        for(int i = 0; i<k;i++){
            pq.push(nums[i]);
        }
        
        // for remaining elements, push only if they are greater than top
        for(int i = k;i<nums.size();i++){
            int element = nums[i];
            if(element > pq.top()){
                pq.pop();
                pq.push(element);
            }
        }
        
        return pq.top();
    }
};