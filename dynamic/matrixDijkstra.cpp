#include <iostream>
#include <vector>
#include <queue>

using namespace::std;

struct node
{
    int row;
    int col;
    int minPath = -1;
    bool isVisited = false;
    int val;
};

bool operator<(node node1, node node2)
{
    return node1.minPath > node2.minPath;
}

bool isInside(int row, int col, vector<vector<node>> &matrix)
{
    return row >= 0 && col >= 0 && row < matrix.size() && col < matrix[row].size();
}

bool isValid(node &cur, vector<vector<node>> &matrix, int newPath)
{
    return (cur.isVisited == false || cur.minPath > newPath + cur.val);
}

void updateMinPath(int row, int col, int &minPath, vector<vector<node>> &matrix)
{
    if (not(isInside(row, col, matrix))) return;
    node adj = matrix[row][col];
    if ((minPath == -1 || adj.minPath < minPath) && adj.minPath != -1) minPath = adj.minPath;
}

void processNode(node &cur, vector<vector<node>> &matrix)
{
    matrix[cur.row][cur.col].isVisited = true;
    int minPath = -1;
             
    updateMinPath(cur.row + 1, cur.col, minPath, matrix);
    updateMinPath(cur.row - 1, cur.col, minPath, matrix);
    updateMinPath(cur.row, cur.col + 1, minPath, matrix);
    updateMinPath(cur.row, cur.col - 1, minPath, matrix);
    updateMinPath(cur.row + 1, cur.col + 1, minPath, matrix);
    updateMinPath(cur.row + 1, cur.col - 1, minPath, matrix);
    updateMinPath(cur.row - 1, cur.col + 1, minPath, matrix);
    updateMinPath(cur.row - 1, cur.col - 1, minPath, matrix);
    
    matrix[cur.row][cur.col].minPath = cur.val + minPath;
}

void pushNode(priority_queue<node> &nodeQueue, int row, int col, vector<vector<node>> &matrix, int newPath)
{
    if (isInside(row, col, matrix) && (isValid(matrix[row][col], matrix, newPath)))
    {
        processNode(matrix[row][col], matrix);
        nodeQueue.push(matrix[row][col]);
    }
}

void addAround(priority_queue<node> &nodeQueue, node &cur, vector<vector<node>> &matrix)
{
    pushNode(nodeQueue, cur.row + 1, cur.col, matrix, cur.minPath);
    pushNode(nodeQueue, cur.row - 1, cur.col, matrix, cur.minPath);
    pushNode(nodeQueue, cur.row, cur.col + 1, matrix, cur.minPath);
    pushNode(nodeQueue, cur.row, cur.col - 1, matrix, cur.minPath);
    pushNode(nodeQueue, cur.row + 1, cur.col + 1, matrix, cur.minPath);
    pushNode(nodeQueue, cur.row + 1, cur.col - 1, matrix, cur.minPath);
    pushNode(nodeQueue, cur.row - 1, cur.col + 1, matrix, cur.minPath);
    pushNode(nodeQueue, cur.row - 1, cur.col - 1, matrix, cur.minPath);
}

int findMinPath(vector<vector<node>> &matrix)
{
    priority_queue<node> nodeQueue;
    matrix[0][0].isVisited = true;
    matrix[0][0].minPath = matrix[0][0].val;
    addAround(nodeQueue, matrix[0][0], matrix);
    while (not(nodeQueue.empty()))
    {
        node cur = nodeQueue.top();
        nodeQueue.pop();
        processNode(cur, matrix);
        addAround(nodeQueue, cur, matrix);
    }
    
    return matrix.back().back().minPath;
}

int main()
{
    int side;
    cin >> side;
    vector<vector<node>> matrix(side, vector<node>(side));
    
    for (int row = 0; row < matrix.size(); row++)
    {
        for(int col = 0; col < matrix[row].size(); col++)
        {
            matrix[row][col].row = row;
            matrix[row][col].col = col;
            cin >> matrix[row][col].val;
        }
    }
    
    cout << findMinPath(matrix);
}
