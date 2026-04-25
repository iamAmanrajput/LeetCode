class Solution {
public:
    long long int MOD = 1000000007;

    int numRollsToTarget(int n, int k, int target) {
        vector<int> prev(target + 1, 0);
        vector<int> curr(target + 1, 0);
        prev[0] = 1;

        for (int i = 1; i <= n; i++) {
            // Reset curr for the current die so old values don't interfere
            fill(curr.begin(), curr.end(), 0);
            for (int j = 1; j <= target; j++) {
                int ans = 0;
                for (int idx = 1; idx <= k; idx++) {
                    if (j - idx >= 0) {
                        ans = (ans + prev[j - idx]) % MOD;
                    };
                }
                curr[j] = ans;
            }
            prev = curr;
        }

        return prev[target];
    }
};