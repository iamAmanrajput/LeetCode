class Solution {
public:
    void solve(string& num1, int a, string& num2, int b, string& ans, int& carry) {
        // base case
        if (a < 0 && b < 0 && carry == 0) {
            return;
        }

        int firstnum = a < 0 ? 0 : num1[a] - '0';
        int secondnum = b < 0 ? 0 : num2[b] - '0';

        int finalnum = firstnum + secondnum + carry;
        int lastdig = finalnum % 10;
        carry = finalnum / 10;

        ans.push_back(lastdig + '0');

        solve(num1, a - 1, num2, b - 1, ans, carry);
    }

    string addStrings(string num1, string num2) {
        int a = num1.size() - 1;
        int b = num2.size() - 1;
        string ans = "";
        int carry = 0;

        solve(num1, a, num2, b, ans, carry);

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
