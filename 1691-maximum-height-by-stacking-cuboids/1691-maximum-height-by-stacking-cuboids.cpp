class Solution {
public:
    bool check(vector<int>& curr, vector<int>& prev) {
        if (curr[0] >= prev[0] && curr[1] >= prev[1] && curr[2] >= prev[2]) {
            return true;
        } else {
            return false;
        }
    }

    int solveUsingTabulationSO(vector<vector<int>>& cuboids) {
        int n = cuboids.size();

        vector<int> currRow(n + 1, 0);
        vector<int> nextRow(n + 1, 0);

        for (int curr_index = n - 1; curr_index >= 0; curr_index--) {
            for (int prev_index = curr_index - 1; prev_index >= -1;
                 prev_index--) {

                int include = 0;
                if (prev_index == -1 ||
                    check(cuboids[curr_index], cuboids[prev_index])) {
                    include = cuboids[curr_index][2] + nextRow[curr_index + 1];
                }

                int exclude = nextRow[prev_index + 1];

                currRow[prev_index + 1] = max(include, exclude);
            }
            // shifting
            nextRow = currRow;
        }

        return nextRow[0];
    }

    int maxHeight(vector<vector<int>>& cuboids) {
        for (auto& cuboid : cuboids) {
            sort(cuboid.begin(), cuboid.end());
        }

        sort(cuboids.begin(), cuboids.end());
        int ans = solveUsingTabulationSO(cuboids);
        return ans;
    }
};