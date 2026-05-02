class Solution {
public:

    // DFS function to detect cycle
    bool isCycleDFS(int src, vector<bool>& vis, vector<bool>& recPath,
                    vector<vector<int>>& adj) {

        vis[src] = true;
        recPath[src] = true;

        // traverse neighbours directly (adj list)
        for (auto v : adj[src]) {

            if (!vis[v]) {
                if (isCycleDFS(v, vis, recPath, adj)) {
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

        // Step 1: Build adjacency list
        vector<vector<int>> adj(numCourses);

        for (auto &p : prerequisites) {
            int a = p[0];
            int b = p[1];
            adj[b].push_back(a); // b -> a
        }

        vector<bool> vis(numCourses, false);
        vector<bool> recPath(numCourses, false);

        // Step 2: Check cycle in every component
        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (isCycleDFS(i, vis, recPath, adj)) {
                    return false; // cycle hai → finish nahi kar sakte
                }
            }
        }

        return true; // no cycle → possible
    }
};