class Solution {
public:

unordered_map<int,list<int>> adj;

    // DFS function to detect cycle
    bool isCycleDFS(int src, vector<bool>& vis, vector<bool>& recPath) {

        vis[src] = true;
        recPath[src] = true;

        // traverse neighbours directly (adj list)
        for (auto v : adj[src]) {

            if (!vis[v]) {
                if (isCycleDFS(v, vis, recPath)) {
                    return true;
                }
            }
            else if (recPath[v]) {
                return true; // cycle found
            }
        }

        recPath[src] = false; // backtrack
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        for (auto &p : prerequisites) {
            int v = p[0];
            int u = p[1];
            adj[u].push_back(v);
        }

        vector<bool> vis(numCourses, false);
        vector<bool> recPath(numCourses, false);

        // Step 2: Check cycle in every component
        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (isCycleDFS(i, vis, recPath)) {
                    return false; // cycle hai → finish nahi kar sakte
                }
            }
        }

        return true; // no cycle → possible
    }
};