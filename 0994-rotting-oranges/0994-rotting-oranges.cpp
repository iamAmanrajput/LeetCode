class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        queue<pair<pair<int, int>, int>> Q; // {{i,j},time}
        int fresh = 0;

        // pushing all sources in Q
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    Q.push({{i, j}, 0});
                    vis[i][j] = true;
                }
            }
        };


        int ans = 0;

        while (!Q.empty()) {
            auto data = Q.front().first;
            int i = data.first;
            int j = data.second;
            int time = Q.front().second;
            Q.pop();
            ans = max(ans, time);

            if ((i - 1 >= 0) && (!vis[i - 1][j]) && (grid[i - 1][j] == 1)) {
                vis[i - 1][j] = true;
                Q.push({{i - 1, j}, time + 1});
            };

            if ((i + 1 < m) && (!vis[i + 1][j]) && (grid[i + 1][j] == 1)) {
                vis[i + 1][j] = true;
                Q.push({{i + 1, j}, time + 1});
            };

            if ((j - 1 >= 0) && (!vis[i][j - 1]) && (grid[i][j - 1] == 1)) {
                vis[i][j - 1] = true;
                Q.push({{i, j - 1}, time + 1});
            };

            if ((j + 1 < n) && (!vis[i][j + 1]) && (grid[i][j + 1] == 1)) {
                vis[i][j + 1] = true;
                Q.push({{i, j + 1}, time + 1});
            };
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ((grid[i][j] == 1) && (vis[i][j] == false)) {
                    ans = -1;
                }
            }
        };

        return ans;
    }
};