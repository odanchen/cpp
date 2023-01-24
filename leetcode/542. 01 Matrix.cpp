class Solution {
public:
    struct cord
    {
        int row;
        int col;
    };
    bool isInside(cord node, vector<vector<int>> &mat)
    {
        return (node.row >= 0 && node.row < mat.size() && node.col >= 0 && node.col < mat[0].size());
    }
    void initializeMatrix(vector<vector<int>> &mat)
    {
        for (int row = 0; row < mat.size(); row++)
        {
            for (int col = 0; col < mat[0].size(); col++)
            {
                mat[row][col] = -1;
            }
        }
    }
    void addNode(queue<cord> &cordQueue, int row, int col, vector<vector<int>> &visMatrix, int &nextTurn, int turn)
    {
        cord node;
        node.row = row;
        node.col = col;
        if (isInside(node, visMatrix) && visMatrix[node.row][node.col] == -1)
        {
            cordQueue.push(node);
            visMatrix[node.row][node.col] = turn;
            nextTurn++;
        }
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<cord> cordQueue;
        vector<vector<int>> visMatrix(mat.size(), vector<int>(mat[0].size()));
        initializeMatrix(visMatrix);
        int turn = 0, toProcess = 0, nextTurn = 0;
    
        for (int row = 0; row < mat.size(); row++)
        {
            for (int col = 0; col < mat[0].size(); col++)
            {
                if (mat[row][col] == 0)
                {
                    addNode(cordQueue, row, col, visMatrix, toProcess, turn);
                }
            }
        }
        turn++;

        while(not(cordQueue.empty()))
        {
            for (int i = 0; i < toProcess; i++)
            {
                cord curNode = cordQueue.front();
                cordQueue.pop();
            
                addNode(cordQueue, curNode.row + 1, curNode.col, visMatrix, nextTurn, turn);
                addNode(cordQueue, curNode.row - 1, curNode.col, visMatrix, nextTurn, turn);
                addNode(cordQueue, curNode.row, curNode.col + 1, visMatrix, nextTurn, turn);
                addNode(cordQueue, curNode.row, curNode.col - 1, visMatrix, nextTurn, turn);
            }
            turn++;
            toProcess = nextTurn;
            nextTurn = 0;
        }

        return visMatrix;
    }
};
