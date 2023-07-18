class Solution {
public:
    int getPerimeter(vector<vector<int>> &grid, int row, int col) {
        int ans = 0;
        grid[row][col] = 2;
        if (row - 1 < 0 or grid[row - 1][col] == 0) ans++;
        else if (grid[row - 1][col] == 1) ans += getPerimeter(grid, row - 1, col);

        if (row + 1 == grid.size() or grid[row + 1][col] == 0) ans++;
        else if (grid[row + 1][col] == 1) ans += getPerimeter(grid, row + 1, col);

        if (col - 1 < 0 or grid[row][col - 1] == 0) ans++;
        else if (grid[row][col - 1] == 1) ans += getPerimeter(grid, row, col - 1);

        if (col + 1 == grid[row].size() or grid[row][col + 1] == 0) ans++;
        else if (grid[row][col + 1] == 1) ans += getPerimeter(grid, row, col + 1);
        return ans;
    }
    int islandPerimeter(vector<vector<int>>& grid) {   
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[row].size(); col++) {
                if (grid[row][col] == 1) return getPerimeter(grid, row, col);
            }
        } 
        return 0;
    }
};
