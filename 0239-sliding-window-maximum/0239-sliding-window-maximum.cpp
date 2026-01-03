class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;

        // first window of k size
        for (int i = 0; i < k; i++) {
            // chote element ko remove kar do
            while (!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }
            // inserting index, so that we can checkout of window element
            dq.push_back(i);
        }

        // store answer for first window
        ans.push_back(nums[dq.front()]);

        // remaining windows ko process karo

        for (int i = k; i < nums.size(); i++) {
            // remove out of window element
            if (!dq.empty() && i - dq.front() >= k) {
                dq.pop_front();
            }

            // ab ferse current element k liye chotte element
            // ko remove krna h
            while (!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }

            // inserting index, so tht we can checkout of window element
            dq.push_back(i);

            // current window ka answer store krna h
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};