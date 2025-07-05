class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int start = 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int end = (matrix.size() * matrix[0].size()) - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            int rowIdx = mid / cols;
            int colIdx = mid % cols;
            if (matrix[rowIdx][colIdx] == target) {
                return true;
            } else if (matrix[rowIdx][colIdx] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return false;
    }
};