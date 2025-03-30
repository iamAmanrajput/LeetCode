class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int n = s.size();
        int start = 0; // Word ka starting index

        for (int i = 0; i <= n; i++) { // n tak chalayenge taaki last word bhi cover ho
            if (i == n || s[i] == ' ') { // Jab space ya string ka end mile
                for (int j = i - 1; j >= start; j--) { // Word ko reverse order me add karein
                    ans.push_back(s[j]);
                }
                if (i != n) ans.push_back(' '); // Last word ke baad space mat lagao
                start = i + 1; // Next word ka start update karo
            }
        }

        return ans;
    }
};
