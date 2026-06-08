class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans;

        // smaller elements
        for (int num : nums)
            if (num < pivot)
                ans.push_back(num);

        // equal elements
        for (int num : nums)
            if (num == pivot)
                ans.push_back(num);

        // greater elements
        for (int num : nums)
            if (num > pivot)
                ans.push_back(num);

        return ans;
    }
};