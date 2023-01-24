class Solution {
public:
    int rob(vector<int>& nums) {
        vector<vector<int>> matrix(((nums.size() + 4) / 3), vector<int>((nums.size() + 1) / 2 + 1));

        for (int row = 0; row < matrix.size(); row++)
        {
            for (int col = 0; col < matrix[row].size(); col++)
            {
                int idx = -2 + row * 3 + col * 2;
                if (idx < 0 || idx >= nums.size()) matrix[row][col] = 0;
                else matrix[row][col] = nums[idx];
            }
        }

        for (int row = 0; row < matrix.size(); row++)
        {
            for (int col = 0; col < matrix[row].size(); col++)
            {
                int add1, add2;
                if (row - 1 < 0) add1 = 0;
                else add1 = matrix[row - 1][col];
                if (col - 1 < 0) add2 = 0;
                else add2 = matrix[row][col - 1];
                matrix[row][col] = max(add1, add2) + matrix[row][col];
            }
        }

        return matrix.back().back();
    }
};
