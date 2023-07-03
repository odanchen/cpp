class Solution {
public:
    struct Cord {
        int row;
        int col;
        int direction = 0;
        vector<pair<int, int>> moves = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        Cord(int row, int col) : row(row), col(col) {}

        void move(vector<vector<int>> &mat, int &turn) {
            if (isTurnNeeded(mat, turn)) makeTurn(turn);
            row += moves[direction].first;
            col += moves[direction].second;
        }

        void set(vector<vector<int>> &matrix, int val) {
            matrix[row][col] = val;
        }

        void makeTurn(int &turn) {
            direction = (direction + 1) % 4;
            if (direction == 3) turn++;
        }

        bool isTurnNeeded(vector<vector<int>> &mat, int turn) {
            switch (direction) {
                case 0: return col >= mat.front().size() - turn - 1;
                case 1: return row >= mat.size() - turn - 1;
                case 2: return col <= turn;
                default: return row <= turn;
            }
        }
    };

    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int>(n));
        int turn = 0;
        Cord cord(0, 0);
        for (int i = 1; i <= n * n; i++) {
            cord.set(mat, i);
            cord.move(mat, turn);
        }
        return mat;
    }
};
