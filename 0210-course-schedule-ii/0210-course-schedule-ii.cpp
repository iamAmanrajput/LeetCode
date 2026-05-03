class Solution {
public:
    unordered_map<int, list<int>> adj;

    bool isCycle(int src, vector<bool>& vis, vector<bool>& recPath) {
        vis[src] = true;
        recPath[src] = true;

        for (int v : adj[src]) {
            if (!vis[v]) {
                if (isCycle(v, vis, recPath)) {
                    return true;
                }
            } else if (recPath[v]) {
                return true;
            }
        }
        recPath[src] = false;
        return false;
    };

    void topologicalSort(int src, vector<bool>& vis, stack<int>& s) {
        vis[src] = true;

        for (int v : adj[src]) {
            if (!vis[v]) {
                topologicalSort(v, vis, s);
            }
        }

        s.push(src);
    };

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> vis(numCourses, false);
        vector<bool> recPath(numCourses, false);
        vector<int> ans;
        stack<int> s;

        for (int i = 0; i < prerequisites.size(); i++) {
            int v = prerequisites[i][0];
            int u = prerequisites[i][1];
            adj[u].push_back(v);
        }

        bool cyclePresent = false;

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (isCycle(i, vis, recPath)) {
                    cyclePresent = true;
                }
            }
        }

        if (cyclePresent) {
            return ans;
        };

        fill(vis.begin(), vis.end(), false);

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                topologicalSort(i, vis, s);
            }
        }

        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};