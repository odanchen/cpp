    struct cord
    {
        int row;
        int col;
    };
    bool isInside(cord node, vector<vector<int>> &mat)
    {
        return (node.row >= 0 && node.row < mat.size() && node.col >= 0 && node.col < mat[0].size());
    }
    void addNode(queue<cord> &cordQueue, int row, int col, vector<vector<int>> &visMatrix, int &nextTurn)
    {
        cord node;
        node.row = row;
        node.col = col;
        if (isInside(node, visMatrix) && visMatrix[node.row][node.col] == 1)
        {
            cordQueue.push(node);
            visMatrix[node.row][node.col] = 2;
            nextTurn++;
        }
    }   
    int orangesRotting(vector<vector<int>>& grid) {
        int turn = 0, toProcess = 0, nextTurn = 0;
        queue<cord> cordQueue;

        for (int row = 0; row < grid.size(); row++)
        {
            for (int col = 0; col < grid[0].size(); col++)
            {
                if (grid[row][col] == 2)
                {
                    cord node;
                    node.row = row;
                    node.col = col;
                    cordQueue.push(node);
                    toProcess++;
                }
            }
        }     

    while(not(cordQueue.empty()))
    {
        for (int i = 0; i < toProcess; i++)
        {
            cord curNode = cordQueue.front();
            cordQueue.pop();
            
            addNode(cordQueue, curNode.row + 1, curNode.col, grid, nextTurn);
            addNode(cordQueue, curNode.row - 1, curNode.col, grid, nextTurn);
            addNode(cordQueue, curNode.row, curNode.col + 1, grid, nextTurn);
            addNode(cordQueue, curNode.row, curNode.col - 1, grid, nextTurn);
        }
        turn++;
        toProcess = nextTurn;
        nextTurn = 0;
    }
        for(vector<int> arr : grid)
        {
            for(int element : arr)
            {
                if (element == 1) return -1;
            }
        }

        if (turn == 0) return 0;
        return turn - 1;     
    }
