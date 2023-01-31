class Solution {
public:
    typedef vector<vector<int>> mat;
    class Cord {
        public:
            int row;
            int col;
            Cord(int row, int col) : row(row), col(col) {}
            Cord colAdd(int diff) {
                return Cord(this->row, this->col + diff);
            }
            Cord rowAdd(int diff) {
                return Cord(this->row + diff, this->col);
            }
            bool isInside(const mat &matrix) {
                return (row >= 0) and (col >= 0) and (row < matrix.size()) and (col < matrix[0].size());
            }
            int val(const mat &matrix) {
                return matrix[row][col];
            }
    };
    bool canBeReached(Cord &prevNode, Cord checkedNode, mat &matrix, mat &bestPaths) {
        return (checkedNode.isInside(matrix)) and 
            (checkedNode.val(bestPaths) != -1) and 
            (checkedNode.val(matrix) > prevNode.val(matrix));
    }
    int getMax(Cord &node, mat &matrix, mat &bestPaths) {
        int ans = 1;
        if (canBeReached(node, node.colAdd(1), matrix, bestPaths)) ans = max(ans, node.colAdd(1).val(bestPaths) + 1);
        if (canBeReached(node, node.colAdd(-1), matrix, bestPaths)) ans = max(ans, node.colAdd(-1).val(bestPaths) + 1);
        if (canBeReached(node, node.rowAdd(1), matrix, bestPaths)) ans = max(ans, node.rowAdd(1).val(bestPaths) + 1);
        if (canBeReached(node, node.rowAdd(-1), matrix, bestPaths)) ans = max(ans, node.rowAdd(-1).val(bestPaths) + 1);
        return ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans = 0;
        vector<vector<int>> bestPaths(matrix.size(), vector<int>(matrix[0].size(), -1));
        vector<Cord> order;
        auto compare = [&](Cord a, Cord b){return a.val(matrix) > b.val(matrix);};

        for (int row = 0; row < matrix.size(); row++) {
            for (int col = 0; col < matrix[row].size(); col++) {
                order.push_back(Cord(row, col));
            }
        }
        sort(order.begin(), order.end(), compare);
        
        for (Cord node : order) {
            bestPaths[node.row][node.col] = getMax(node, matrix, bestPaths);
            ans = max(ans, bestPaths[node.row][node.col]);
        }

        return ans;
    }
};
