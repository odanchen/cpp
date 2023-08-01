class Solution {
public:
    int getVal(int val, int row, int col, vector<vector<int>> &grid) {
        if (row < 0 or col < 0 or row >= grid.size() or col >= grid[row].size()) return val;
        return max(0, val - grid[row][col]);
    }

    int surfaceArea(vector<vector<int>> &grid) {
        int ans = 0;
        vector<pair<int, int>> dirs = {{1,  0}, {0,  1}, {-1, 0}, {0,  -1}};
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[row].size(); col++) {
                for (auto cord: dirs) ans += getVal(grid[row][col], row + cord.first, col + cord.second, grid);
                if (grid[row][col] != 0) ans += 2;
            }
        }
        return ans;
    }
};
