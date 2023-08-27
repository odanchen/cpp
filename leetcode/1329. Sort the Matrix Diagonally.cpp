class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        for (int i = 0; i < mat.size() + mat[0].size() - 1; i++) {
            int row = i >= mat.size() ? 0 : i;
            int col = i < mat.size() ? 0 : i - mat.size() + 1;
            vector<int> arr;
            while (row < mat.size() and col < mat[row].size()) {
                arr.push_back(mat[row++][col++]);
            }
            sort(arr.begin(), arr.end());
            while (row > 0 and col > 0) {
                mat[--row][--col] = arr.back();
                arr.pop_back();
            }
        }
        return mat;
    }
};
