class Solution {
public:
    bool attacks(vector<int> &queen, vector<int> &king, vector<vector<bool>> &mat) {
        if (queen[0] == king[0]) {
            for (int i = min(king[1], queen[1]) + 1; i < max(king[1], queen[1]); i++) {
                if (mat[queen[0]][i]) return false;
            }
            return true;
        }
        if (queen[1] == king[1]) {
            for (int i = min(king[0], queen[0]) + 1; i < max(king[0], queen[0]); i++) {
                if (mat[i][queen[1]]) return false;
            }
            return true;
        }
        if (abs(queen[0] - king[0]) == abs(queen[1] - king[1])) {
            int rDiff = queen[0] - king[0] > 0 ? -1 : 1, row = queen[0];
            int cDiff = queen[1] - king[1] > 0 ? -1 : 1, col = queen[1];
            while (row != king[0] - rDiff and col != king[1] - cDiff) {
                if (mat[row += rDiff][col += cDiff]) return false;
            }
            return true;
        }
        return false;
    }

    vector<vector<int>> queensAttacktheKing(vector<vector<int>> &queens, vector<int> &king) {
        vector<vector<int>> ans;
        vector<vector<bool>> mat(8, vector<bool>(8));
        for (auto &queen: queens) mat[queen[0]][queen[1]] = true;
        mat[king[0]][king[1]] = true;
        copy_if(queens.begin(), queens.end(), back_inserter(ans), 
            [&](vector<int> &a) { return attacks(a, king, mat); });
        return ans;
    }
};
