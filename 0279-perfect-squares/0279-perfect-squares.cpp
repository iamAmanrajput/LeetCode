class Solution {
public:
    int solve(int n, vector<int>& squares, vector<int>& dp) {

        if (n == 0)
            return 0;

        if (dp[n] != -1)
            return dp[n];

        int mini = INT_MAX;

        for (int square : squares) {

            if (square > n)
                break;

            int ans = solve(n - square, squares, dp);

            mini = min(mini, ans + 1);
        }

        return dp[n] = mini;
    }

    int numSquares(int n) {

        vector<int> squares;

        for (int i = 1; i * i <= n; i++)
            squares.push_back(i * i);

        vector<int> dp(n + 1, -1);

        return solve(n, squares, dp);
    }
};