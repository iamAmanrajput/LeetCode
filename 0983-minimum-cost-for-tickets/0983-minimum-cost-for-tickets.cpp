class Solution {
public:
    int solve(int i, vector<int>& days, vector<int>& costs, vector<int>& dp) {

        if (i >= days.size())
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int oneDay = costs[0] + solve(i + 1, days, costs, dp);

        int j = i;
        while (j < days.size() && days[j] <= days[i] + 6) {
            j++;
        }

        int sevenDay = costs[1] + solve(j, days, costs, dp);

        int k = i;
        while (k < days.size() && days[k] <= days[i] + 29) {
            k++;
        }

        int thirtyDay = costs[2] + solve(k, days, costs, dp);

        return dp[i] = min(oneDay, min(sevenDay, thirtyDay));
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {

        vector<int> dp(days.size(), -1);

        return solve(0, days, costs, dp);
    }
};