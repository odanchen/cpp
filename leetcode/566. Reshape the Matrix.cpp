class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int>> ans(r, vector<int>(c));
        if ((r * c) != (mat.size() * mat[0].size())) return mat;
        int idx = 0;
        for (vector<int> row : mat)
        {
            for (int element : row)
            {
                ans[idx / c][idx % c] = element;
                idx++;
            }
        }
        return ans;
    }
};
