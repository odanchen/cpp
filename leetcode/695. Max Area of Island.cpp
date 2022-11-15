    void fill(int row, int col, vector<vector<int>>& grid, int &cnt)
    {
        if (grid[row][col] == 1) 
        {
            grid[row][col] = 2;
            cnt++;
        }

        if(col + 1 < grid[row].size() && grid[row][col + 1] == 1)
            fill(row, col + 1, grid, cnt);
        if(col - 1 >= 0  && grid[row][col - 1] == 1)
            fill(row, col - 1, grid, cnt);
        if(row + 1 < grid.size()  && grid[row + 1][col] == 1)
            fill(row + 1, col, grid, cnt);
        if(row - 1 >= 0 && grid[row - 1][col] == 1)
            fill(row - 1, col, grid, cnt);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for (int row = 0; row < grid.size(); row++)
        {
            for (int col = 0; col < grid[row].size(); col++)
            {
                if(grid[row][col] == 1)
                {
                    int cnt = 0;
                    fill(row, col, grid, cnt);
                    ans = max(cnt, ans);
                }
            }
        }
        return ans;
    }
