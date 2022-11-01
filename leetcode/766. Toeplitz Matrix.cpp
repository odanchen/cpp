    bool isDiagonal(vector<vector<int>>& matrix, int row, int col)
    {
        int num = matrix[row][col];
        while(row < matrix.size() && col < matrix[0].size())
        {
            if (matrix[row][col] != num) return false;
            row++;
            col++;
        }
        return true;
    }

    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for(int i = matrix.size() - 1; i >= 0; i--)
            if (not(isDiagonal(matrix, i, 0))) return false;

        for(int i = matrix[0].size() - 1; i >= 0; i--)
            if (not(isDiagonal(matrix, 0, i))) return false;

        return true;
    }
