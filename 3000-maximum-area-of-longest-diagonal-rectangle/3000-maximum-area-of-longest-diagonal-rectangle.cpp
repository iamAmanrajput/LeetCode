class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        long long maxDiag = 0;
        int maxArea = 0;

        for (auto& d : dimensions) {
            int l = d[0], w = d[1];
            long long diagSq = 1LL * l * l + 1LL * w * w;  // diagonal squared
            int area = l * w;

            if (diagSq > maxDiag || (diagSq == maxDiag && area > maxArea)) {
                maxDiag = diagSq;
                maxArea = area;
            }
        }

        return maxArea;
    }
};
