class Solution {
public:
    int minDistance(string& a, string& b) {
        vector<int> next(a.length() + 1, 0);
        vector<int> curr(a.length() + 1, 0);

        // for (int col = 0; col <= b.length(); col++) {
        //     dp[a.length()][col] = b.length() - col;
        // }

        for (int row = 0; row <= a.length(); row++) {
            next[row] = a.length() - row;
        }

        for (int j = b.length() - 1; j >= 0; j--) {
            // har new column ke last cell me ans insert karo
            curr[a.length()] = b.length() - j;
            for (int i = a.length() - 1; i >= 0; i--) {

                int ans = 0;
                if (a[i] == b[j]) {
                    ans = 0 + next[i + 1];
                } else {
                    int replace = 1 + next[i + 1];
                    int insert = 1 + next[i];
                    int remove = 1 + curr[i + 1];

                    ans = min(insert, min(remove, replace));
                }
                curr[i] = ans;
            }
            next = curr;
        }

        return next[0];
    }
};