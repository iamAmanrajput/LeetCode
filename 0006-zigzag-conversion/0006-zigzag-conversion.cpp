class Solution {
public:
    string convert(string s, int numRows) {

        if (numRows == 1)
            return s;

        vector<string> rows(numRows);

        int row = 0;
        bool goingDown = true;

        for (char ch : s) {

            rows[row].push_back(ch);

            if (row == numRows - 1)
                goingDown = false;

            else if (row == 0)
                goingDown = true;

            row += (goingDown ? 1 : -1);
        }

        string ans;

        for (string str : rows)
            ans += str;

        return ans;
    }
};