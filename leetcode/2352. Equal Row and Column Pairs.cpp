class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> cnt;
        int ans = 0;
        for (auto line : grid) cnt[line]++;
        for (int col = 0; col < grid[0].size(); col++) {
            vector<int> line(grid.size());
            for (int row = 0; row < grid.size(); row++) line[row] = grid[row][col];
            ans+= cnt[line];
        }
        return ans;
    }
};
