class Solution {
public:
    vector<pair<int, int>> dir = {{1,  0},{0,  1},{-1, 0},{0,  -1},{1,  1},{-1, 1},{-1, -1},{1,  -1}};

    bool inside(vector<vector<char>> &board, int row, int col) {
        return row >= 0 and row < board.size() and col >= 0 and col < board[row].size();
    }

    int checkAdj(vector<vector<char>> &board, int row, int col) {
        return count_if(dir.begin(), dir.end(), [&](pair<int, int> &cord) {
            return inside(board, row + cord.first, col + cord.second) and board[row + cord.first][col + cord.second] == 'M';
        });
    }

    void fillAdj(vector<vector<char>> &board, int row, int col) {
        if (board[row][col] != 'E') return;
        if (checkAdj(board, row, col) != 0) {
            board[row][col] = checkAdj(board, row, col) + '0';
            return;
        }
        board[row][col] = 'B';
        for (auto& [r, c]: dir) {
            if (inside(board, row + r, col + c)) fillAdj(board, row + r, col + c);
        }
    }

    vector<vector<char>> updateBoard(vector<vector<char>> &board, vector<int> &click) {
        if (board[click.front()][click.back()] == 'M') board[click.front()][click.back()] = 'X';
        else fillAdj(board, click.front(), click.back());
        return board;
    }
};
