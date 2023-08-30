class Solution {
public:
    int permute(vector<vector<int>> &grid, int row, int col, int cnt) {
        if (row < 0 or col < 0 or row >= grid.size() or col >= grid[row].size()) return 0;
        if (grid[row][col] == 2 and cnt == 0) return 1;
        if (grid[row][col] == -1 or (grid[row][col] == 2 and cnt > 0)) return 0;

        cnt--;
        grid[row][col] = -1;
        int ans = permute(grid, row + 1, col, cnt) + permute(grid, row - 1, col, cnt) + 
                permute(grid, row, col + 1, cnt) + permute(grid, row, col - 1, cnt);
        grid[row][col] = 0;

        return ans;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int cnt = 1, rBegin, cBegin;
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0;  col < grid[row].size(); col++) {
                if (grid[row][col] == 0) cnt++;
                if (grid[row][col] == 1) rBegin = row, cBegin = col;
            }
        }
        return permute(grid, rBegin, cBegin, cnt);
    }
};
