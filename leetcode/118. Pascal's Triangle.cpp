class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle(numRows);
        for (int i = 0; i < triangle.size(); i++) triangle[i].resize(i + 1);

        for (int row = 0; row < triangle.size(); row++)
        {
            for (int col = 0; col < triangle[row].size(); col++)
            {
                if (col == 0 || col == triangle[row].size() - 1) triangle[row][col] = 1;
                else triangle[row][col] = triangle[row - 1][col] + triangle[row - 1][col - 1];
            }
        }

        return triangle;
    }
};
