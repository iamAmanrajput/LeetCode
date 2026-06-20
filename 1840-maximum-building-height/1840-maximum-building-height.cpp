class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {

        restrictions.push_back({1, 0});
        restrictions.push_back({n, n - 1});

        sort(restrictions.begin(), restrictions.end());

        int m = restrictions.size();

        // Left -> Right
        for (int i = 1; i < m; i++) {
            restrictions[i][1] = min(
                restrictions[i][1],
                restrictions[i - 1][1] + (restrictions[i][0] - restrictions[i - 1][0])
            );
        }

        // Right -> Left
        for (int i = m - 2; i >= 0; i--) {
            restrictions[i][1] = min(
                restrictions[i][1],
                restrictions[i + 1][1] + (restrictions[i + 1][0] - restrictions[i][0])
            );
        }

        int ans = 0;

        // Calculate maximum peak between adjacent restrictions
        for (int i = 1; i < m; i++) {
            int x1 = restrictions[i - 1][0];
            int h1 = restrictions[i - 1][1];

            int x2 = restrictions[i][0];
            int h2 = restrictions[i][1];

            int dist = x2 - x1;

            ans = max(ans, (h1 + h2 + dist) / 2);
        }

        return ans;
    }
};