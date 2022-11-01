    void moveLeft(int &row, int &col)
    {
        row++;
        col--;
    }

    void moveRight(int &row, int &col)
    {
        row++;
        col++;
    }

    bool isLocked(vector<vector<int>>& grid, int row, int col)
    {
        if (col == 0 && grid[row][col] == -1) return true;
        if (col == grid[0].size() - 1 && grid[row][col] == 1) return true;
        if (grid[row][col] == 1 && grid[row][col + 1] == -1) return true;
        if (grid[row][col] == -1 && grid[row][col - 1] == 1) return true;
        return false;
    }

    int findSingleBall(vector<vector<int>>& grid, int col)
    {
        int row = 0;
        while(row < grid.size())
        {
            if(isLocked(grid, row, col)) return -1;

            if(grid[row][col] == 1) moveRight(row, col);
            else moveLeft(row, col);
        }

        return col;
    }

    vector<int> findBall(vector<vector<int>>& grid) 
    {
        vector<int> ans;
        for (int i = 0; i < grid[0].size(); i++)
        {
            ans.push_back(findSingleBall(grid, i));
        }

        return ans;
    }
