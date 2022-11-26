    const int wall = 1;
    const int clear = 0;
    struct cord
    {
        int row;
        int col;
        cord(int _row, int _col) : row(_row), col(_col) {}
    };
    bool isInside(int row, int col, vector<vector<int>> &grid)
    {
        return (row >= 0 && col >= 0 && row < grid.size() && col < grid[0].size());
    }
    void addNode(int row, int col, vector<vector<int>> &visMatrix, vector<vector<int>> &grid , int &nextTurn, queue<cord> 
        &nodeQueue)
    {
        if(isInside(row, col, visMatrix) && visMatrix[row][col] == 0 && grid[row][col] == clear)
        {
            nextTurn++;
            visMatrix[row][col] = 1;
            nodeQueue.push(cord(row, col));
        }
    }
    void addAround(int row, int col, vector<vector<int>> &visMatrix, vector<vector<int>> &grid, int &nextTurn, queue<cord> 
        &nodeQueue)
    {
        addNode(row + 1, col, visMatrix, grid, nextTurn, nodeQueue);
        addNode(row - 1, col, visMatrix, grid, nextTurn, nodeQueue);
        addNode(row, col + 1, visMatrix, grid, nextTurn, nodeQueue);
        addNode(row, col - 1, visMatrix, grid, nextTurn, nodeQueue);
        addNode(row + 1, col + 1, visMatrix, grid, nextTurn, nodeQueue);
        addNode(row + 1, col - 1, visMatrix, grid, nextTurn, nodeQueue);
        addNode(row - 1, col + 1, visMatrix, grid, nextTurn, nodeQueue);
        addNode(row - 1, col - 1, visMatrix, grid, nextTurn, nodeQueue);
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<vector<int>> visMatrix(grid.size(), vector<int>(grid[0].size()));
        int turn = 0;
        int toVisit = 0, nextTurn = 0;
        queue<cord> nodeQueue;
        addNode(0, 0, visMatrix, grid, toVisit, nodeQueue);
        bool found = false;

        while(!nodeQueue.empty() && !found)
        {
            turn++;
            for(int i = 0; i < toVisit; i++)
            {
                cord node = nodeQueue.front();
                nodeQueue.pop();
                addAround(node.row, node.col, visMatrix, grid, nextTurn, nodeQueue);
                if (node.row == grid.size() - 1 && node.col == grid[0].size() - 1) found = true;
            }
            toVisit = nextTurn;
            nextTurn = 0;
        }

        return (visMatrix.back().back() == 0) ? -1 : turn;
    }
