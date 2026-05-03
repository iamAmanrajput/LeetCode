class Solution {
public:
    unordered_map<int, list<int>> adj;

    bool isCycle(int src, vector<bool>& vis, vector<bool>& recPath,
                 stack<int>& s) {
        vis[src] = true;
        recPath[src] = true;

        for (int v : adj[src]) {
            if (!vis[v]) {
                if (isCycle(v, vis, recPath, s)) {
                    return true;
                }
            } else if (recPath[v]) {
                return true;
            }
        }
        recPath[src] = false;
        s.push(src);
        return false;
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
                if (isCycle(i, vis, recPath, s)) {
                    cyclePresent = true;
                }
            }
        }

        if (cyclePresent) {
            return ans;
        };

        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};