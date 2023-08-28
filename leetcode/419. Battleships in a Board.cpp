class Solution {
public:
    void dfs(int row, int col, vector<vector<char>> &board) {
        if (row < 0 or col < 0 or row >= board.size() or col >= board[row].size()) return;
        if (board[row][col] != 'X') return;

        board[row][col] = 'Y';
        dfs(row + 1, col, board);
        dfs(row - 1, col, board);
        dfs(row, col + 1, board);
        dfs(row, col - 1, board);
    }
    int countBattleships(vector<vector<char>>& board) {
        int ans = 0;
        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[row].size(); col++) {
                if (board[row][col] == 'X') {
                    dfs(row, col, board);
                    ans++;
                }
            }
        }
        return ans;
    }
};
