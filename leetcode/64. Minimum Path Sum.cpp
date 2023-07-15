class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[row].size(); col++) {
                if (row == 0 and col == 0) continue;
                else if (row == 0) grid[row][col] += grid[row][col - 1];
                else if (col == 0) grid[row][col] += grid[row - 1][col];
                else grid[row][col] += min(grid[row - 1][col], grid[row][col - 1]);
            }
        }
        return grid.back().back();
    }
};
