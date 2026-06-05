class Solution {
public:
    struct Node {
        long long cnt;   // number of valid numbers
        long long wave;  // total waviness
    };

    string s;
    Node dp[20][11][3][2][2];
    bool vis[20][11][3][2][2];

    Node dfs(int pos,
             int prevDigit,
             int prevCmp, // -1,0,1
             bool tight,
             bool started) {

        if (pos == s.size()) {
            return {1, 0};
        }

        if (vis[pos][prevDigit][prevCmp + 1][tight][started]) {
            return dp[pos][prevDigit][prevCmp + 1][tight][started];
        }

        vis[pos][prevDigit][prevCmp + 1][tight][started] = true;

        Node res = {0, 0};

        int limit = tight ? s[pos] - '0' : 9;

        for (int d = 0; d <= limit; d++) {

            bool newTight = tight && (d == limit);

            if (!started && d == 0) {

                Node nxt = dfs(
                    pos + 1,
                    10,      // dummy digit
                    0,
                    newTight,
                    false
                );

                res.cnt += nxt.cnt;
                res.wave += nxt.wave;
            }
            else if (!started) {

                Node nxt = dfs(
                    pos + 1,
                    d,
                    0,
                    newTight,
                    true
                );

                res.cnt += nxt.cnt;
                res.wave += nxt.wave;
            }
            else {

                int cmp = 0;

                if (d > prevDigit) cmp = 1;
                else if (d < prevDigit) cmp = -1;

                int add = 0;

                if (prevCmp != 0 &&
                    cmp != 0 &&
                    prevCmp != cmp) {
                    add = 1;
                }

                Node nxt = dfs(
                    pos + 1,
                    d,
                    cmp,
                    newTight,
                    true
                );

                res.cnt += nxt.cnt;
                res.wave += nxt.wave + nxt.cnt * add;
            }
        }

        return dp[pos][prevDigit][prevCmp + 1][tight][started] = res;
    }

    long long solve(long long n) {
        if (n < 0) return 0;

        s = to_string(n);

        memset(vis, 0, sizeof(vis));

        return dfs(0, 10, 0, true, false).wave;
    }

    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};