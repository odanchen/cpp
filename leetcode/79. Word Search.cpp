class Solution {
public:
    bool permute(vector<vector<char>> &board, int idx, string &word, int row, int col) {
        if (idx == word.size()) return true;
        if (row < 0 or col < 0 or row >= board.size() or col >= board[row].size()) return false;
        if (board[row][col] != word[idx]) return false;

        idx++;
        char c = board[row][col];
        board[row][col] = '0';
        bool ans = permute(board, idx, word, row + 1, col) or permute(board, idx, word, row - 1, col) or
                permute(board, idx, word, row, col + 1) or permute(board, idx, word, row, col - 1);
        board[row][col] = c;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[row].size(); col++) {
                if (permute(board, 0, word, row, col)) return true;
            }
        }
        return false;
    }
};
