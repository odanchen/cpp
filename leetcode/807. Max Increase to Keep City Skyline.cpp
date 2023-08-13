class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> side(grid.size()), front(grid.size());
        int ans = 0;
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[row].size(); col++)  {
                side[row] = max(side[row], grid[row][col]);
                front[col] = max(front[col], grid[row][col]);
            }
        }
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[row].size(); col++)  {
                ans += max(0, min(side[row], front[col]) - grid[row][col]);
            }
        }
        return ans;
    }
};
