class Solution {
public:
    bool isPalindrome(string s) {
        string ans = "";

        // Remove non-alphanumeric characters and convert to lowercase
        for (char ch : s) {
            if (isalnum(ch)) {
                ans.push_back(tolower(ch));
            }
        }

        int start = 0, end = ans.size() - 1;

        // Two-pointer approach
        while (start <= end) {
            if (ans[start] != ans[end]) {
                return false;
            }
            start++;
            end--;
        }

        return true;
    }
};
