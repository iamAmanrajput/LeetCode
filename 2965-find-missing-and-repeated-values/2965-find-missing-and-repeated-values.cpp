class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int total = n * n;

        // Frequency array 1..n^2 ke liye
        vector<int> freq(total + 1, 0);

        // Step 1: Traverse grid aur count karo
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                freq[grid[i][j]]++;
            }
        }

        int repeated = -1, missing = -1;

        // Step 2: Frequency check karke repeat/missing nikalo
        for (int num = 1; num <= total; num++) {
            if (freq[num] == 2) repeated = num;
            if (freq[num] == 0) missing = num;
        }

        return {repeated, missing};
    }
};
