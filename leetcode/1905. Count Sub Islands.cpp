    bool isInside(int row, int col, vector<vector<int>> &grid)
    {
        return (row >= 0 && col >= 0 && row < grid.size() && col < grid[row].size());
    }
    void fill(int row, int col, vector<vector<int>>& grid, bool &isEdge, vector<vector<int>>& grid2)
    {
        if (isInside(row, col, grid) && (grid[row][col] != 0 && grid2[row][col] == 0)) isEdge = true;

        if (isInside(row, col, grid) && grid[row][col] == 1)
        {
            grid[row][col] = 2;
            fill(row, col + 1, grid, isEdge, grid2);
            fill(row, col - 1, grid, isEdge, grid2);
            fill(row + 1, col, grid, isEdge, grid2);
            fill(row - 1, col, grid, isEdge, grid2);
        }
    }
 
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int cnt = 0;
        for (int row = 0; row < grid1.size(); row++)
        {
            for (int col = 0; col < grid1[row].size(); col++)
            {
                if (grid2[row][col] == 1)
                {
                    bool isEdge = false;
                    fill(row, col, grid2, isEdge, grid1);
                    if (isEdge == false) cnt++;
                }
            }
        }
        return cnt;
    }
