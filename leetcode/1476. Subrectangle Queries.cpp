class SubrectangleQueries {
private:
    vector<vector<int>> rectangle;
public:
    SubrectangleQueries(vector<vector<int>> &rectangle) : rectangle(rectangle) {}

    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        while (row1 <= row2) {
            for (int i = col1; i <= col2; i++) rectangle[row1][i] = newValue;
            row1++;
        }
    }

    int getValue(int row, int col) {
        return rectangle[row][col];
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */
