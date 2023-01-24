class Solution {
public:
    void moveUp(int &row, int &col)
    {
        row--;
        col++;
    }
    void moveDown(int &row, int &col)
    {
        row++;
        col--;
    }
    bool onBorder(int row, int col, vector<vector<int>>& mat, bool directionUp)
    {  
        bool ans = (directionUp && (row == 0 || col == mat[0].size() - 1));
        ans = ans || (not(directionUp) && (col == 0 || row == mat.size() - 1));
        return ans;
    }
    void adjust(int &row, int &col, vector<vector<int>>& mat, bool &directionUp)
    {
        if (row == mat.size() - 1 && col == mat[0].size() - 1) return;

        if(directionUp)
        {
            if (col == mat[0].size() - 1) row++;
            else col++;
        }
        else
        {
            if(row == mat.size() - 1) col++;
            else row++;
        }
        directionUp = not(directionUp);
    }
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int maxlen = mat.size() * mat[0].size();
        ans.resize(maxlen);

        int row = 0;
        int col = 0;
        int idx = 0;

        bool directionUp = true;
        while(idx < maxlen)
        {
            while(not(onBorder(row, col, mat, directionUp)))
            {
                if (directionUp)
                {
                    ans[idx] = mat[row][col];
                    moveUp(row, col);
                    idx++;
                }
                else 
                {
                    ans[idx] = mat[row][col];
                    moveDown(row, col);
                    idx++;
                }
            }
            ans[idx] = mat[row][col];
            idx++;
            adjust(row, col, mat, directionUp);
        }

        return ans;
    }
};
