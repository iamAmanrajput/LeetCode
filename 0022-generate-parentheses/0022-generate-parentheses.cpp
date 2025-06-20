class Solution {
public:
    void solve(vector<string>& ans, int open, int close, string output) {
        // base case
        if (open == 0 && close == 0) {
            ans.push_back(output);
            return;
        }

        // include open bracket
        if (open > 0) {
            output.push_back('(');
            solve(ans, open - 1, close, output);
            output.pop_back(); // backtrack
        }

        // include close bracket
        if (close > open) {
            output.push_back(')');
            solve(ans, open, close - 1, output);
            output.pop_back(); // backtrack
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(ans, n, n, "");
        return ans;
    }
};
