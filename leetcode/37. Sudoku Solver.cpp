class Solution {
public:
    vector<vector<char>> ans;
    void fillRowValues(int row, vector<vector<char>> &board, bool valuesFound[]) {
        for (char val : board[row]) {
            if (val != '.') valuesFound[val - '1'] = true;
        }
    }
    void fillColValues(int col, vector<vector<char>> &board, bool valuesFound[]) {
        for (int row = 0; row < 9; row++) {
            if (board[row][col] != '.') valuesFound[board[row][col] - '1'] = true;
        }
    }
    void fillSquareValues(int row, int col, vector<vector<char>> &board, bool valuesFound[]) {
        int rStart = row / 3, cStart = col / 3;
        for (int r = rStart * 3; r < rStart * 3 + 3; r++) {
            for (int c = cStart * 3; c < cStart * 3 + 3; c++) {
                if (board[r][c] != '.') valuesFound[board[r][c] - '1'] = true;
            }
        }
    }
    void fillValues(int row, int col, vector<vector<char>> &board, bool valuesFound[]) {
        fillRowValues(row, board, valuesFound);
        fillColValues(col, board, valuesFound);
        fillSquareValues(row, col, board, valuesFound);
    }
    vector<char> getPlacingOptions(int row, int col, vector<vector<char>> &board) {
        bool valuesFound[9] = {0};
        fillValues(row, col, board, valuesFound);
        vector<char> ans;
        for (int val = 0; val < 9; val++) {
            if(!valuesFound[val]) ans.push_back(val + '1');
        }
        return ans;
    }
    void solve(int row, int col, vector<vector<char>> board) {
        if (row == 9) {
            ans = board;
            return;
        }
        if (!ans.empty()) return;
        int nextRow = row + (col + 1) / 9;
        int nextCol = (col + 1) % 9;
        if (board[row][col] != '.') solve(nextRow, nextCol, board);
        else {
            for (char option : getPlacingOptions(row, col, board)) {
                board[row][col] = option;
                solve(nextRow, nextCol, board);
                board[row][col] = '.';
            }
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(0, 0, board);
        board = ans;
    }
};
