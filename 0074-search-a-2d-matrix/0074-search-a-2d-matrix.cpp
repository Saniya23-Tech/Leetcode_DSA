class Solution {
public:
    bool searchInRow(vector<vector<int>> &mat, int target, int row) {
        int n = mat[0].size(); 
        int st = 0, end = n - 1;  

        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (target == mat[row][mid]) {
                return true;
            } else if (target > mat[row][mid]) {
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int stR = 0, endR = m - 1;

        while (stR <= endR) {
            int midRow = stR + (endR - stR) / 2;

            if (target >= matrix[midRow][0] && target <= matrix[midRow][n - 1]) {
                return searchInRow(matrix, target, midRow);
            } else if (target > matrix[midRow][n - 1]) {  
                stR = midRow + 1;
            } else {
                endR = midRow - 1;
            }
        }

        return false;
    }
};
