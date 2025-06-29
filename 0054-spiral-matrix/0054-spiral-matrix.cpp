class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int firstRow = 0;
        int lastRow = matrix.size() - 1;
        int firstCol = 0;
        int lastCol = matrix[0].size() - 1;
        int count = 0;
        int totalElem = matrix.size() * matrix[0].size();
        vector<int> ans;

        while (count < totalElem) {
            // printing first row
            for (int i = firstCol; i <= lastCol && count < totalElem; i++) {
                ans.push_back(matrix[firstRow][i]);
                count++;
            }

            firstRow++;

            // printing last col
            for (int i = firstRow; i <= lastRow && count < totalElem; i++) {
                ans.push_back(matrix[i][lastCol]);
                count++;
            }

            lastCol--;

            // printing last row
            for (int i = lastCol; i >= firstCol && count < totalElem; i--) {
                ans.push_back(matrix[lastRow][i]);
                count++;
            }

            lastRow--;

            // printing first col
            for (int i = lastRow; i >= firstRow && count < totalElem; i--) {
                ans.push_back(matrix[i][firstCol]);
                count++;
            }

            firstCol++;
        }

        return ans;
    }
};