    bool isInside(int row, int col, vector<vector<int>> &grid)
    {
        return (row >= 0 && col >= 0 && row < grid.size() && col < grid[row].size());
    }
    bool isOnEdge(int row, int col, vector<vector<int>> &grid)
    {
        return (row == 0 || col == 0 || row == grid.size() - 1 || col == grid[0].size() - 1);
    }
    void fill(int row, int col, vector<vector<int>>& grid, bool &isEdge, int &cnt)
    {
        if (isInside(row, col, grid) && isOnEdge(row, col, grid) && grid[row][col] == 1) isEdge = true;

        if (isInside(row, col, grid) && grid[row][col] == 1)
        {
            grid[row][col] = 2;
            cnt++;
            fill(row, col + 1, grid, isEdge, cnt);
            fill(row, col - 1, grid, isEdge, cnt);
            fill(row + 1, col, grid, isEdge, cnt);
            fill(row - 1, col, grid, isEdge, cnt);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int cnt = 0;
        for (int row = 0; row < grid.size(); row++)
        {
            for (int col = 0; col < grid[row].size(); col++)
            {
                if (grid[row][col] == 1)
                {
                    bool isEdge = false;
                    int size = 0;
                    fill(row, col, grid, isEdge, size);
                    if (isEdge == false) cnt += size;
                }
            }
        }
        return cnt;
    }   
