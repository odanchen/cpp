/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* createNode(vector<vector<int>>& grid, int row, int col, int size) {
        int val = grid[row][col];
        bool status = true;
        for (int row1 = row; row1 < row + size and status; row1++) {
            for (int col1 = col; col1 < col + size and status; col1++) {
                if (grid[row1][col1] != val) status = false;
            }
        }
        if (status) return new Node(val, true);
        return new Node(0, false, createNode(grid, row, col, size / 2), 
                createNode(grid, row, col + size / 2, size / 2),
                createNode(grid, row + size / 2, col, size / 2),
                createNode(grid, row + size / 2, col + size / 2, size / 2));
    }
    Node* construct(vector<vector<int>>& grid) {
        return createNode(grid, 0, 0, grid.size());
    }
};
