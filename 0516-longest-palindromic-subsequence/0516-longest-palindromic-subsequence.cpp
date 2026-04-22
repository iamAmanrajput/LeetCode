#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {

        // Step 1: reverse string
        string b = s;
        reverse(b.begin(), b.end());

        /*
        Using LCS (space optimized)

        Time Complexity: O(n * n)
        Space Complexity: O(n)
        */

        vector<int> curr(s.length() + 1, 0);
        vector<int> next(s.length() + 1, 0);

        for (int j = b.length() - 1; j >= 0; j--) {
            for (int i = s.length() - 1; i >= 0; i--) {

                if (s[i] == b[j]) {
                    curr[i] = 1 + next[i + 1];
                } else {
                    curr[i] = max(next[i], curr[i + 1]);
                }
            }
            next = curr;
        }

        return next[0];
    }
};