    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0;
        int row1 = 0, col1 = 0, row2 = 0, col2 = mat[0].size() - 1;
        while(row1 < mat.size())
        {
            sum += mat[row1][col1];
            if (col1 != col2) sum += mat[row2][col2];
            row1++; col1++; row2++; col2--;
        }
        return sum;
    }
