class Solution {
public:
    bool isInside(int row, int col, vector<vector<char>> &grid)
    {
        return (row >= 0 && col >= 0 && row < grid.size() && col < grid[row].size());
    }
    void fill(int row, int col, vector<vector<char>> &grid)
    {
        if (isInside(row, col, grid) && grid[row][col] == '1') 
        {
            grid[row][col] = '2';
            fill(row + 1, col, grid);
            fill(row - 1, col, grid);
            fill(row, col + 1, grid);
            fill(row, col - 1, grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        for (int row = 0; row < grid.size(); row++)
        {
            for (int col = 0; col < grid[row].size(); col++)
            {
                if (grid[row][col] == '1') 
                {
                    cnt++;
                    fill(row, col, grid);
                }
            }
        }
        return cnt;
    }
};
