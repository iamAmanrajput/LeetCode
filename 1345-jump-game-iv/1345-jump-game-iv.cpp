class Solution {
public:
    int minJumps(vector<int>& arr) {

        int n = arr.size();

        if (n == 1)
            return 0;

        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        queue<int> q;
        vector<bool> vis(n, false);

        q.push(0);
        vis[0] = true;

        int steps = 0;

        while (!q.empty()) {

            int size = q.size();

            while (size--) {

                int curr = q.front();
                q.pop();

                if (curr == n - 1)
                    return steps;

                // i + 1
                if (curr + 1 < n && !vis[curr + 1]) {
                    vis[curr + 1] = true;
                    q.push(curr + 1);
                }

                // i - 1
                if (curr - 1 >= 0 && !vis[curr - 1]) {
                    vis[curr - 1] = true;
                    q.push(curr - 1);
                }

                // same value indices
                for (int idx : mp[arr[curr]]) {

                    if (!vis[idx]) {
                        vis[idx] = true;
                        q.push(idx);
                    }
                }

                // important optimization
                mp[arr[curr]].clear();
            }

            steps++;
        }

        return -1;
    }
};