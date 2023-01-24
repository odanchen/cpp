class Solution {
public:
    const int land = 1;
    const int water = 0;
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
    void addNode(int row ,int col, vector<vector<int>> &vis, vector<vector<int>> &grid , int &nextTurn, queue<cord> &queue)
    {
        if(isInside(row, col, vis) && vis[row][col] == 0)
        {
            nextTurn++;
            vis[row][col] = 1;
            queue.push(cord(row, col));
        }
    }
    void fill(int row, int col, vector<vector<int>>& vis, vector<vector<int>> &grid, int &nextTurn, queue<cord> &queue)
    {
        if (isInside(row, col, grid) && grid[row][col] == land && vis[row][col] == 0) 
        {
            vis[row][col] = 2;
            queue.push(cord(row, col));
            nextTurn++;
            fill(row, col + 1, vis, grid, nextTurn, queue);
            fill(row, col - 1, vis, grid, nextTurn, queue);
            fill(row + 1, col, vis, grid, nextTurn, queue);
            fill(row - 1, col, vis, grid, nextTurn, queue);
        }
    }
    void addAround(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid, int &nextTurn, queue<cord> &queue)
    {
        addNode(row + 1, col, vis, grid, nextTurn, queue);
        addNode(row - 1, col, vis, grid, nextTurn, queue);
        addNode(row, col + 1, vis, grid, nextTurn, queue);
        addNode(row, col - 1, vis, grid, nextTurn, queue);
    }
    int shortestBridge(vector<vector<int>>& grid) {
        vector<vector<int>> visMatrix(grid.size(), vector<int>(grid[0].size()));
        int turn = 0;
        int toVisit = 0, nextTurn = 0;
        queue<cord> nodeQueue;
        bool found = false;

        for(int row = 0; row < grid.size() && found == false; row++)
        {
            for(int col = 0; col < grid[row].size() && found == false; col++)
            {
                if (grid[row][col] == land)
                {
                    found = true;
                    fill(row, col, visMatrix, grid, toVisit, nodeQueue);
                }
            }
        }

        while(!nodeQueue.empty())
        {
            for(int i = 0; i < toVisit; i++)
            {
                cord node = nodeQueue.front();
                nodeQueue.pop();

                if (grid[node.row][node.col] == land && visMatrix[node.row][node.col] != 2) return turn -1;

                addAround(node.row, node.col, visMatrix, grid, nextTurn, nodeQueue);
            }
            turn++;
            toVisit = nextTurn;
            nextTurn = 0;
        }

        return 0;
    }
};
