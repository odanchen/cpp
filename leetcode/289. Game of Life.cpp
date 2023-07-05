class Solution {
public:
    vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
    bool isOutside(vector<vector<int>> &mat, int row, int col) {
        return row < 0 or col < 0 or row >= mat.size() or col >= mat[row].size();
    }
    int getState(vector<vector<int>> &mat, int row, int col) {
        int cnt = 0;
        for (auto move : dir) {
            int row1 = row + move.first, col1 = col + move.second;
            if (!isOutside(mat, row1, col1) and mat[row1][col1] & 1) cnt++;
        }    
        return (cnt == 3 or (cnt == 2 and mat[row][col])) ? 2 : 0;
    }
    void gameOfLife(vector<vector<int>>& board) {
        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[row].size(); col++) board[row][col] |= getState(board, row, col);
        }   
        for (auto &row : board) {
            for (auto &col : row) col = col >> 1;
        }
    }
};
