class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {

        vector<int> mpA(A.size() + 1, 0);
        vector<int> mpB(B.size() + 1, 0);
        int ans = 0;

        vector<int> finalAns;

        for (int i = 0; i < A.size(); i++) {
            int elemA = A[i];
            int elemB = B[i];
            mpA[elemA]++;
            mpB[elemB]++;

            if (mpB[elemA]) {
                ans++;
            }
            if (mpA[elemB] && A[i] != B[i]) {
                ans++;
            }
            finalAns.push_back(ans);
        }

        return finalAns;
    }
};