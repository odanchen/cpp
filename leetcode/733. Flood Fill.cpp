    bool isInside(int row, int col, vector<vector<int>> &image)
    {
        return (row >= 0 && col >= 0 && row < image.size() && col < image[row].size());
    }
    void fill(int row, int col, int color, vector<vector<int>>& image, int startColor)
    {
        if (isInside(row, col, image) && image[row][col] == startColor) 
        {
            image[row][col] = color;
            fill(row, col + 1, color, image, startColor);
            fill(row, col - 1, color, image, startColor);
            fill(row + 1, col, color, image, startColor);
            fill(row - 1, col, color, image, startColor);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (color != image[sr][sc]) fill(sr, sc, color, image, image[sr][sc]);
        return image;
    }
