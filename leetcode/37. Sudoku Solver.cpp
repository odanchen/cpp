class Solution {
public:
    bool isFound = false;
    vector<set<char>> rowVals = vector<set<char>>(9, set<char>());
    vector<set<char>> colVals = vector<set<char>>(9, set<char>());
    vector<set<char>> boxVals = vector<set<char>>(9, set<char>());
    void fillRowValues(vector<vector<char>> &board) {
        for (int row = 0; row < 9; row++) {
            for (char digit : board[row]) {
                if (digit != '.') rowVals[row].insert(digit);
            }
        }
    }
    void fillColValues(vector<vector<char>> &board) {
        for (int col = 0; col < 9; col++) {
            for (int row = 0; row < 9; row++) {
                if (board[row][col] != '.') colVals[col].insert(board[row][col]);
            }
        }
    }
    void fillBoxValues(vector<vector<char>> &board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                int idx = (row / 3) * 3 + col / 3;
                if (board[row][col] != '.') boxVals[idx].insert(board[row][col]);
            }
        }
    }
    vector<char> getPlacingOptions(int row, int col) {
        vector<char> ans;
        int idx = (row / 3) * 3 + col / 3;
        for (char i = '1'; i <= '9'; i++) {
            if (rowVals[row].find(i) == rowVals[row].end() and
                colVals[col].find(i) == colVals[col].end() and
                boxVals[idx].find(i) == boxVals[idx].end()) ans.push_back(i);
        }
        return ans;
    }
    void solve(int row, int col, vector<vector<char>> &board) {
        if (row == 9) {
            isFound = true;
            return;
        }
        if (isFound) return;
        int nextRow = row + (col + 1) / 9;
        int nextCol = (col + 1) % 9;
        if (board[row][col] != '.') solve(nextRow, nextCol, board);
        else {
            for (char option : getPlacingOptions(row, col)) {
                if (isFound) return;
                board[row][col] = option;
                rowVals[row].insert(option);
                colVals[col].insert(option);
                boxVals[(row / 3) * 3 + col / 3].insert(option);
                solve(nextRow, nextCol, board);

                if (isFound) return;
                board[row][col] = '.';
                rowVals[row].erase(option);
                colVals[col].erase(option);
                boxVals[(row / 3) * 3 + col / 3].erase(option);
            }
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        fillRowValues(board);
        fillColValues(board);
        fillBoxValues(board);
        solve(0, 0, board);
    }
};
