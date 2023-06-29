class Solution {
public:
    void moveUp(int &row, int &col) {
        row--;
        col++;
    }
    void moveDown(int &row, int &col) {
        row++;
        col--;
    }
    bool onBorder(int row, int col, vector<vector<int>>& mat, bool directionUp) {  
        return (directionUp && (row == 0 || col == mat[0].size() - 1)) || 
            (!(directionUp) && (col == 0 || row == mat.size() - 1));
    }
    void adjust(int &row, int &col, vector<vector<int>>& mat, bool &directionUp) {
        if (row == mat.size() - 1 && col == mat[0].size() - 1) return;

        if (directionUp) {
            if (col == mat[0].size() - 1) row++;
            else col++;
        } else {
            if(row == mat.size() - 1) col++;
            else row++;
        }
        directionUp = !directionUp;
    }
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int maxlen = mat.size() * mat[0].size();
        vector<int> ans(maxlen);

        int row = 0, col = 0, idx = 0;
        bool directionUp = true;

        while(idx < maxlen) {
            while(!(onBorder(row, col, mat, directionUp))) {
                ans[idx++] = mat[row][col];
                if (directionUp) moveUp(row, col);
                else moveDown(row, col);
            }
            ans[idx++] = mat[row][col];
            adjust(row, col, mat, directionUp);
        }

        return ans;
    }
};
