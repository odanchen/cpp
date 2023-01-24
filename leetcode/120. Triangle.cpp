class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int row = 1; row < triangle.size(); row++)
        {
            for (int col = 0; col < triangle[row].size(); col++)
            {
                int topLeft, topRight;

                if (col - 1 < 0) topLeft = INT_MAX;
                else topLeft = triangle[row - 1][col - 1];
                if (col >= triangle[row - 1].size()) topRight = INT_MAX;
                else topRight = triangle[row - 1][col];

                triangle[row][col] = triangle[row][col] + min(topLeft, topRight);
            }
        }
        int minPath = triangle.back()[0];
        for (int path : triangle.back()) if (path < minPath) minPath = path;
        return minPath;
    }
};
