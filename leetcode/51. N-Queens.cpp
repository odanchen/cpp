class Solution {
public:
    int getLeftDiag(int row, int col) {
        return row + col;
    }
    int getRightDiag(int row, int col, int n) {
        row = n - 1 - row;
        return row + col;
    }
    bool canBePlaces(int row, int col, int n, set<int> &cols, set<int> &leftDiags, set<int> &rightDiags) {
        return (cols.find(col) == cols.end()) and 
        (leftDiags.find(getLeftDiag(row, col)) == leftDiags.end()) and 
        (rightDiags.find(getRightDiag(row, col, n)) == rightDiags.end());
    }
    void solve(int n, vector<string> cur, int row, set<int> cols, set<int> leftDiags, set<int> rightDiags, vector<vector<string>> &ans) {
        if (row == n) {
            ans.push_back(cur);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (canBePlaces(row, col, n, cols, leftDiags, rightDiags)) {
                cur[row][col] = 'Q';
                cols.insert(col); leftDiags.insert(getLeftDiag(row, col)); rightDiags.insert(getRightDiag(row, col, n));
                solve(n, cur, row + 1, cols, leftDiags, rightDiags, ans);
                cur[row][col] = '.';
                cols.erase(col); leftDiags.erase(getLeftDiag(row, col)); rightDiags.erase(getRightDiag(row, col, n));
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> cur(n, string(n, '.'));

        solve(n, cur, 0, set<int>(), set<int>(), set<int>(), ans);
        return ans;
    }
};
