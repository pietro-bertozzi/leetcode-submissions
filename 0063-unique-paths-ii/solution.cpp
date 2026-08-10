class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (obstacleGrid[i][j] == 1) obstacleGrid[i][j] = 0;
                else if (!i && !j) obstacleGrid[i][j] = 1;
                else obstacleGrid[i][j] =
                    (i ? obstacleGrid[i - 1][j] : 0) +
                    (j ? obstacleGrid[i][j - 1] : 0);
            }
        }
        return obstacleGrid[n - 1][m - 1];
    }
};
