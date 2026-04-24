class Solution {
public:
    // Custom comparator for sorting
    static bool compare(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) {
            // If widths are same, sort height in descending order
            return a[1] > b[1];
        }
        // Otherwise, sort width in ascending order
        return a[0] < b[0];
    };

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        if (n == 0)
            return 0;

        // Step 1: Sort the envelopes
        sort(envelopes.begin(), envelopes.end(), compare);

        // Step 2: Find LIS of the heights using Binary Search
        vector<int> ans;
        ans.push_back(envelopes[0][1]);

        for (int i = 1; i < n; i++) {
            int currentHeight = envelopes[i][1];

            if (currentHeight > ans.back()) {
                // If current height is greater than the largest element in our
                // LIS, append it
                ans.push_back(currentHeight);
            } else {
                // Otherwise, find the first element >= currentHeight and
                // replace it lower_bound uses binary search internally: O(log
                // n)
                int index = lower_bound(ans.begin(), ans.end(), currentHeight) -
                            ans.begin();
                ans[index] = currentHeight;
            }
        }

        return ans.size();
    };
};