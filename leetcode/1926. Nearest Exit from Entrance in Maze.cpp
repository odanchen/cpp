    struct cord
    {
        int row;
        int col;
    };
    bool isInside(int row, int col, vector<vector<char>> &mat)
    {
        return (row >= 0 && row < mat.size() && col >= 0 && col < mat[0].size());
    }
    bool isAns(int row, int col, vector<vector<char>> &maze, vector<int> &entrance)
    {
        return isInside(row, col, maze) 
            && (((row == 0 || col == 0 || row == maze.size() - 1 || col == maze[row].size() - 1) 
            && not(row == entrance[0] && col == entrance[1])) && maze[row][col] == '.');
    }
    void addNode(queue<cord> &cordQueue, int row, int col, vector<vector<char>> &maze, int &nextTurn, int turn)
    {
        cord node;
        node.row = row;
        node.col = col;
        if (isInside(row, col, maze) && maze[node.row][node.col] == '.')
        {
            cordQueue.push(node);
            maze[node.row][node.col] = '-';
            nextTurn++;
        }
    }
          
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<cord> cordQueue;
        int turn = 0, toProcess = 0, nextTurn = 0;

        addNode(cordQueue, entrance[0], entrance[1], maze, toProcess, turn);
        turn++;

        while(not(cordQueue.empty()))
        {
            for (int i = 0; i < toProcess; i++)
            {
                cord curNode = cordQueue.front();
                cordQueue.pop();

                if (isAns(curNode.row + 1, curNode.col, maze, entrance)) return turn;
                addNode(cordQueue, curNode.row + 1, curNode.col, maze, nextTurn, turn);
                if (isAns(curNode.row - 1, curNode.col, maze, entrance)) return turn;
                addNode(cordQueue, curNode.row - 1, curNode.col, maze, nextTurn, turn);
                if (isAns(curNode.row, curNode.col + 1, maze, entrance)) return turn;
                addNode(cordQueue, curNode.row, curNode.col + 1, maze, nextTurn, turn);
                if (isAns(curNode.row, curNode.col - 1, maze, entrance)) return turn;
                addNode(cordQueue, curNode.row, curNode.col - 1, maze, nextTurn, turn);
            }
            turn++;
            toProcess = nextTurn;
            nextTurn = 0;
        }
        return -1;
    }
