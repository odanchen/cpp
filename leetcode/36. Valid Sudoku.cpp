class Solution {
public:
    bool areRowsCorrect(vector<vector<char>> &board) {
        for (vector<char> row : board) {
            bool arr[9] = {0};
            for (char val : row) {
                if (val != '.') {
                    if (arr[val - 1 - '0']) return false;
                    arr[val - 1 - '0'] = true;
                }
            }
        }
        return true;
    }
    bool areColsCorrect(vector<vector<char>> &board) {
        for (int col = 0; col < 9; col++) {
            bool arr[9] = {0};
            for (int row = 0; row < 9; row++) {
                if (board[row][col] != '.') {
                    if (arr[board[row][col] - 1 - '0']) return false;
                    arr[board[row][col] - 1 - '0'] = true;
                }
            }
        }
        return true;
    }
    bool checkSquare(vector<vector<char>> &board, int sRow, int sCol) {
        bool arr[9] = {0};
        for (int row = sRow * 3; row < sRow * 3 + 3; row++) {
            for (int col = sCol * 3; col < sCol * 3 + 3; col++) {
                if (board[row][col] != '.') {
                    if (arr[board[row][col] - 1 - '0']) return false;
                    arr[board[row][col] - 1 - '0'] = true;
                }
            }
        }
        return true;
    }
    bool areSquaresCorrect(vector<vector<char>> &board) {
        for (int sRow = 0; sRow < 3; sRow++) {
            for (int sCol = 0; sCol < 3; sCol++) {
                if (!checkSquare(board, sRow, sCol)) return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        return areRowsCorrect(board) and areColsCorrect(board) and areSquaresCorrect(board);
    }
};
