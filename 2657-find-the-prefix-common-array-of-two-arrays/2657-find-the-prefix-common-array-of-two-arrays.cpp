class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {

        // Track which elements have appeared in A's prefix
        vector<int> mpA(A.size() + 1, 0);
        // Track which elements have appeared in B's prefix
        vector<int> mpB(B.size() + 1, 0);
        int ans = 0; // stores count of common elements till current index

        vector<int> finalAns;

        for (int i = 0; i < A.size(); i++) {
            int elemA = A[i];
            int elemB = B[i];
            // Mark current elements as visited
            mpA[elemA]++;
            mpB[elemB]++;

            // If current A[i] was already seen in B's prefix,
            // then it becomes a new common element
            if (mpB[elemA]) {
                ans++;
            }
            // If current B[i] was already seen in A's prefix,
            // then it becomes a new common element
            // Avoid double counting when A[i] == B[i]
            if (mpA[elemB] && A[i] != B[i]) {
                ans++;
            }
            // Store prefix common count till index i
            finalAns.push_back(ans);
        }

        return finalAns;
    }
};