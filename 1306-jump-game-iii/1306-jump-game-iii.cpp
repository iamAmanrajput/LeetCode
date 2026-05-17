class Solution {
public:

    bool solve(vector<int>& arr, int start, vector<bool>& vis) {
        if (start >= arr.size() || start < 0 || vis[start]) {
            return false;
        }

        if (arr[start] == 0) {
            return true;
        }

        vis[start] = true;

        bool Ans1 = solve(arr, start + arr[start], vis);
        bool Ans2 = solve(arr, start - arr[start], vis);

        return Ans1 || Ans2;
    }

    bool canReach(vector<int>& arr, int start) {
        vector<bool> vis(arr.size(), false);

        return solve(arr, start, vis);
    }
};