class Solution {
public:
    int getMax(int row, int col, vector<vector<int>> &grid) {
        int ans = grid[row][col];
        for (int r = 0; r < 3; r++) {
            for (int c = 0; c < 3; c++) ans = max(ans, grid[row + r][col + c]);
        }
        return ans;
    }
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>> ans(grid.size() - 2, vector<int>(grid.size() - 2));
        for (int row = 0; row < grid.size() - 2; row++) {
            for (int col = 0; col < grid[row].size() - 2; col++) ans[row][col] = getMax(row, col, grid);
        }
        return ans;
    }
};
