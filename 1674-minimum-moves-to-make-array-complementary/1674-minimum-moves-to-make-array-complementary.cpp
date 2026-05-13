class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();

        // Difference array to track move changes
        vector<int> diff(2 * limit + 2, 0);

        for (int i = 0; i < n / 2; i++) {

            int a = nums[i];
            int b = nums[n - 1 - i];

            int low = min(a, b) + 1;
            int high = max(a, b) + limit;
            int sum = a + b;

            // Initially assume 2 moves for every sum
            diff[2] += 2;

            // From low to high -> can be done in 1 move
            diff[low] -= 1;
            diff[high + 1] += 1;

            // Exact sum -> needs 0 moves
            diff[sum] -= 1;
            diff[sum + 1] += 1;
        }

        int ans = INT_MAX;
        int moves = 0;

        // Check all possible target sums
        for (int s = 2; s <= 2 * limit; s++) {
            moves += diff[s];
            ans = min(ans, moves);
        }

        return ans;
    }
};