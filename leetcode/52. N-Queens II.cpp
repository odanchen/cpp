class Solution {
public:
    typedef vector<bool> vBool;
    typedef vector<string> vStr;

    int getLeftDiag(int row, int col) {
        return row + col;
    }
    int getRightDiag(int row, int col, int n) {
        row = n - 1 - row;
        return row + col;
    }
    bool canBePlaces(int row, int col, int n, vBool &cols, vBool &leftDiags, vBool &rightDiags) {
        return (!cols[col]) and (!leftDiags[getLeftDiag(row, col)]) and (!rightDiags[getRightDiag(row, col, n)]);
    }
    void solve(int n, vStr cur, int row, vBool cols, vBool leftDiags, vBool rightDiags, vector<vStr> &ans) {
        if (row == n) {
            ans.push_back(cur);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (canBePlaces(row, col, n, cols, leftDiags, rightDiags)) {
                cur[row][col] = 'Q';
                cols[col] = true; leftDiags[getLeftDiag(row, col)] = true; rightDiags[getRightDiag(row, col, n)] = true;
                solve(n, cur, row + 1, cols, leftDiags, rightDiags, ans);
                cur[row][col] = '.';
                cols[col] = false; 
                leftDiags[getLeftDiag(row, col)] = false; rightDiags[getRightDiag(row, col, n)] = false;
            }
        }
    }
    int totalNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> cur(n, string(n, '.'));
        int len = 2 * n - 1;
        solve(n, cur, 0, vector<bool>(len, false), vector<bool>(len, false), vector<bool>(len, false), ans);
        return ans.size();
    }
};
