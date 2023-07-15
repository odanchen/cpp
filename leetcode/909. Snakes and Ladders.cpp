class Solution {
public:
    struct Cord {
        int row;
        int col;
        Cord(pair<int, int> node) : row(node.first), col(node.second) {}
        int getVal(vector<vector<int>> &board) {return board[row][col];}
    };
    Cord getCord(int curr, int size) {
        curr--;
        int row = size - 1 - curr / size;
        int col = (row & 1) == (size & 1) ? size - curr % size - 1 : curr % size;
        return Cord({row, col});
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        queue<int> nodeQueue({1});
        vector<bool> visited(board.size() * board.size() + 1, false);
        int turn = 0;
        while (!nodeQueue.empty()) {
            int toProcess = nodeQueue.size();
            for (int i = 0; i < toProcess; i++) {
                int curr = nodeQueue.front();
                if (curr == board.size() * board.size()) return turn;
                nodeQueue.pop();
                for (int next = curr + 1; next < visited.size() and next <= curr + 6; next++) {
                    if (getCord(next, board.size()).getVal(board) == -1) {
                        if (!visited[next]) nodeQueue.push(next);
                        visited[next] = true;
                    } else {
                        if (!visited[getCord(next, board.size()).getVal(board)])
                            nodeQueue.push(getCord(next, board.size()).getVal(board));
                        visited[getCord(next, board.size()).getVal(board)] = true;
                    }
                }
            }
            turn++;
        }
        return -1;
    }
};
