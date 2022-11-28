    const int land = 1;
    const int water = 0;
    struct cord
    {
        int row;
        int col;
        int val;
        bool isPacific;
        bool isAtlantic;
        cord(int _row, int _col) : row(_row), col(_col), isPacific(false), isAtlantic(false) {}
        cord() : isPacific(false), isAtlantic(false) {}
    };
    bool isInside(int row, int col, vector<vector<int>> &grid)
    {
        return (row >= 0 && col >= 0 && row < grid.size() && col < grid[0].size());
    }
    void addNode(int row ,int col, vector<vector<int>> &vis, vector<vector<cord>> &grid , int &nextTurn, queue<cord> &queue)
    {
        if(isInside(row, col, vis) && vis[row][col] == 0)
        {
            nextTurn++;
            vis[row][col] = 1;
            queue.push(cord(row, col));
        }
    }
    void addAround(int row, int col, vector<vector<int>> &vis, vector<vector<cord>> &grid, int &nextTurn, queue<cord> &queue)
    {
        if (isInside(row + 1, col, vis) && grid[row + 1][col].val >= grid[row][col].val) 
            addNode(row + 1, col, vis, grid, nextTurn, queue);
        if (isInside(row - 1, col, vis) && grid[row - 1][col].val >= grid[row][col].val) 
            addNode(row - 1, col, vis, grid, nextTurn, queue);
        if (isInside(row, col + 1, vis) && grid[row][col + 1].val >= grid[row][col].val) 
            addNode(row, col + 1, vis, grid, nextTurn, queue);
        if (isInside(row, col - 1, vis) && grid[row][col - 1].val >= grid[row][col].val) 
            addNode(row, col - 1, vis, grid, nextTurn, queue);
    }
    void markNodes(vector<vector<cord>> &grid, bool isPacific)
    {
        vector<vector<int>> visMatrix(grid.size(), vector<int>(grid[0].size()));
        int toVisit = 0, nextTurn = 0;
        queue<cord> nodeQueue;

        if (isPacific) 
        {
            for (int row = 0; row < grid.size(); row++) addNode(row, 0, visMatrix, grid, toVisit, nodeQueue);
            for (int col = 0; col < grid[0].size(); col++) addNode(0, col, visMatrix, grid, toVisit, nodeQueue);
        }
        else
        {
            for (int row = 0; row < grid.size(); row++) addNode(row,grid[row].size()-1, visMatrix, grid, toVisit, nodeQueue);
            for (int col = 0; col < grid[0].size(); col++) addNode(grid.size()-1, col, visMatrix, grid, toVisit, nodeQueue);
        }
        while(!nodeQueue.empty())
        {
            for(int i = 0; i < toVisit; i++)
            {
                cord node = nodeQueue.front();
                nodeQueue.pop();

                if (isPacific) grid[node.row][node.col].isPacific = true;
                else grid[node.row][node.col].isAtlantic = true;

                addAround(node.row, node.col, visMatrix, grid, nextTurn, nodeQueue);
            }
            toVisit = nextTurn;
            nextTurn = 0;
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<cord>> grid(heights.size(), vector<cord>(heights[0].size()));
        for (int row = 0; row < heights.size(); row++)
        {
            for (int col = 0; col < heights[row].size(); col++)
            {
                grid[row][col].row = row;
                grid[row][col].col = col;
                grid[row][col].val = heights[row][col];
            }
        }
        markNodes(grid, true);
        markNodes(grid, false);

        vector<vector<int>> ans;
        for (vector<cord> line : grid)
        {
            for (cord node : line) if (node.isAtlantic && node.isPacific) ans.push_back(vector<int>{node.row, node.col});
        } 
        return ans;
    }
