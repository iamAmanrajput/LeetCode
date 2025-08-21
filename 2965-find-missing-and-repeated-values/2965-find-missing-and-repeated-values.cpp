class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        long long total = 1LL * n * n;

        // Expected sums
        long long S = total * (total + 1) / 2;                   // expected sum
        long long Q = total * (total + 1) * (2 * total + 1) / 6; // expected square sum

        long long S1 = 0, Q1 = 0;

        // Actual sums
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                long long val = grid[i][j];
                S1 += val;
                Q1 += val * val;
            }
        }

        long long diff = S1 - S;         // a - b
        long long sumAB = (Q1 - Q) / diff; // a + b

        long long a = (diff + sumAB) / 2;
        long long b = a - diff;

        return {(int)a, (int)b};
    }
};
