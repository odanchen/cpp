class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>> &grid) {
        vector<int> rowZeros(grid.size()), rowOnes(grid.size());
        vector<int> colZeros(grid[0].size()), colOnes(grid[0].size());
        for (int row = 0; row < grid.size(); row++) {
            rowZeros[row] = count(grid[row].begin(), grid[row].end(), 0);
            rowOnes[row] = grid[row].size() - rowZeros[row];
        }
        for (int col = 0; col < grid[0].size(); col++) {
            for (auto &row: grid) colZeros[col] += (row[col] == 0);
            colOnes[col] = grid.size() - colZeros[col];
        }
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[row].size(); col++) {
                grid[row][col] = rowOnes[row] + colOnes[col] - rowZeros[row] - colZeros[col];
            }
        }
        return grid;
    }
};
