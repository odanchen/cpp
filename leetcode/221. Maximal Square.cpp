class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans = 0;
        vector<vector<int>> memo(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (int row = 0; row < matrix.size(); row++) {
            for (int col = 0; col < matrix[row].size(); col++) {
                if (matrix[row][col] == '1') {
                    if (row == 0 or col == 0) memo[row][col] = 1;
                    else {
                        int minSurr = min(memo[row - 1][col], min(memo[row][col - 1], memo[row - 1][col - 1]));
                        memo[row][col] = minSurr + 1;
                    }
                    ans = max(ans, memo[row][col] * memo[row][col]);
                }
            }
        }
        return ans;
    }
};
