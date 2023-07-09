class Solution {
public:
    void setRow(vector<vector<int>> &matrix, int row) {
        for (int col = 0; col < matrix[row].size(); col++) matrix[row][col] = 0;
    }
    void setCol(vector<vector<int>> &matrix, int col) {
        for (int row = 0; row < matrix.size(); row++) matrix[row][col] = 0;
    }
    void setZeroes(vector<vector<int>>& matrix) {
        bool firstRow = any_of(matrix.front().begin(), matrix.front().end(), [](int a){return a == 0;});
        bool firstCol = any_of(matrix.begin(), matrix.end(), [](vector<int> &a){return a.front() == 0;});
        for (int row = 1; row < matrix.size(); row++) {
            for (int col = 1; col < matrix[row].size(); col++) {
                if (matrix[row][col] == 0) {
                    matrix[0][col] = 0;
                    matrix[row][0] = 0;
                }
            }
        }

        for (int col = 1; col < matrix[0].size(); col++) if (matrix[0][col] == 0) setCol(matrix, col);
        for (int row = 1; row < matrix.size(); row++) if (matrix[row][0] == 0) setRow(matrix, row);
        if (firstRow) setRow(matrix, 0);
        if (firstCol) setCol(matrix, 0);
    }
};
