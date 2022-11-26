    const int land = 1;
    const int water = 0;
    struct cord
    {
        int row;
        int col;
        cord(int _row, int _col) : row(_row), col(_col) {}
    };
    void initializeMatrix(vector<vector<int>> &visMatrix)
    {
        for(int row = 0; row < visMatrix.size(); row++)
        {
            for(int col = 0; col < visMatrix[0].size(); col++)
            {
                visMatrix[row][col] = -1;
            }
        }
    }
    bool isInside(int row, int col, vector<vector<int>> &grid)
    {
        return (row >= 0 && col >= 0 && row < grid.size() && col < grid[0].size());
    }
    void addNode(int row, int col, int turn, vector<vector<int>> &visMatrix, int &nextTurn, queue<cord> &nodeQueue)
    {
        if(isInside(row, col, visMatrix) && visMatrix[row][col] == -1)
        {
            nextTurn++;
            visMatrix[row][col] = turn;
            nodeQueue.push(cord(row, col));
        }
    }
    int maxDistance(vector<vector<int>>& grid) {
        vector<vector<int>> visMatrix(grid.size(), vector<int>(grid[0].size()));
        initializeMatrix(visMatrix);
        int turn = 0;
        int toVisit = 0, nextTurn = 0;
        queue<cord> nodeQueue;

        for(int row = 0; row < grid.size(); row++)
        {
            for (int col = 0; col < grid[row].size(); col++)
            {
                if (grid[row][col] == land)
                {
                    addNode(row, col, turn, visMatrix, toVisit, nodeQueue);
                }
            }
        }

        while(!nodeQueue.empty())
        {
            turn++;
            for(int i = 0; i < toVisit; i++)
            {
                cord node = nodeQueue.front();
                nodeQueue.pop();
                addNode(node.row + 1, node.col, turn, visMatrix, nextTurn, nodeQueue);
                addNode(node.row - 1, node.col, turn, visMatrix, nextTurn, nodeQueue);
                addNode(node.row, node.col + 1, turn, visMatrix, nextTurn, nodeQueue);
                addNode(node.row, node.col - 1, turn, visMatrix, nextTurn, nodeQueue);
            }
            toVisit = nextTurn;
            nextTurn = 0;
        }

        return (turn < 2) ? -1 : turn -1;
    }
