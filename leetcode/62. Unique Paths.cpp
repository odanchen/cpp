class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m, vector<int>(n));
        grid[0][0] = 1;
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[row].size(); col++) {
                grid[row][col] += ((row == 0) ? 0 : grid[row - 1][col]) + ((col == 0) ? 0 : grid[row][col - 1]);
            }
        }
        return grid.back().back();
    }
};
