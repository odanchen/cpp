class Solution {
public:
    void fill(vector<vector<char>> &board, int row, int col, char letter) {
        if (row < 0 or col < 0 or row == board.size() or col == board[row].size() or board[row][col] != 'O')
                return;
        board[row][col] = letter;
        fill(board, row + 1, col, letter);
        fill(board, row - 1, col, letter);
        fill(board, row, col + 1, letter);
        fill(board, row, col - 1, letter); 
    }
    void replace(vector<vector<char>> &board, char letter) {
        for (int row = 0; row < board.size(); row++) {
            if (board[row][0] == 'O') fill(board, row, 0, letter);
            if (board[row].back() == 'O') fill(board, row, board[row].size() - 1, letter);
        }
        for (int col = 0; col < board.front().size(); col++) {
            if (board[0][col] == 'O') fill(board, 0, col, letter);
            if (board.back()[col] == 'O') fill(board, board.size() - 1, col, letter);
        }
    }
    void solve(vector<vector<char>>& board) {
        replace(board, 'T');
        for (int row = 1; row < board.size() - 1; row++) {
            for (int col = 1; col < board[row].size() - 1; col++) fill(board, row, col, 'X');
        }
        for (auto &row : board) {
            for (char &letter : row) if (letter == 'T') letter = 'O';
        }
    }
};
