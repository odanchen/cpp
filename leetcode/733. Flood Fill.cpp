    void fill(int row, int col, int color, vector<vector<int>>& image, int startColor)
    {
        if (image[row][col] == startColor) image[row][col] = color;

        if(col + 1 < image[row].size()  && image[row][col + 1] == startColor)
            fill(row, col + 1, color, image, startColor);
        if(col - 1 >= 0  && image[row][col - 1] == startColor)
            fill(row, col - 1, color, image, startColor);
        if(row + 1 < image.size()  && image[row + 1][col] == startColor)
            fill(row + 1, col, color, image, startColor);
        if(row - 1 >= 0 && image[row - 1][col] == startColor)
            fill(row - 1, col, color, image, startColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (color != image[sr][sc]) fill(sr, sc, color, image, image[sr][sc]);
        return image;
    }
