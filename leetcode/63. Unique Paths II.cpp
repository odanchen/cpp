class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        obstacleGrid[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1;
        for (int row = 1; row < obstacleGrid.size(); row++) {
            obstacleGrid[row][0] = obstacleGrid[row][0] == 1 ? 0 : obstacleGrid[row - 1][0];
        }
        for (int col = 1; col < obstacleGrid.front().size(); col++) {
            obstacleGrid[0][col] = obstacleGrid[0][col] == 1 ? 0 : obstacleGrid[0][col - 1];
        }
        for (int row = 1; row < obstacleGrid.size(); row++) {
            for (int col = 1; col < obstacleGrid[row].size(); col++) {
                obstacleGrid[row][col] = obstacleGrid[row][col] == 1 ? 
                    0 : obstacleGrid[row - 1][col] + obstacleGrid[row][col - 1]; 
            }
        }
        return obstacleGrid.back().back();
    }
};
