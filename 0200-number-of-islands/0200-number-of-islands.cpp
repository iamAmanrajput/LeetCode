class Solution {
public:
    void dfs(int i, int j, vector<vector<bool>>& vis,
             vector<vector<char>>& grid, int n, int m) {
        if (i < 0 || j < 0 || i >= n || j >= m || vis[i][j] ||
            grid[i][j] != '1') {
            return;
        }

        vis[i][j] = true;

        // visit neighbours
        dfs(i - 1, j, vis, grid, n, m); // top
        dfs(i, j + 1, vis, grid, n, m); // right
        dfs(i + 1, j, vis, grid, n, m); // bottom
        dfs(i, j - 1, vis, grid, n, m); // left
    };

    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        int m = grid.size();    // rows
        int n = grid[0].size(); // columns

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    dfs(i, j, vis, grid, m, n);
                    islands++;
                }
            }
        }

        return islands;
    }
};