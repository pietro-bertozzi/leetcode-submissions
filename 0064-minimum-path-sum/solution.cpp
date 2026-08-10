class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!i && !j) continue;
                grid[i][j] += min(
                    i ? grid[i - 1][j] : INT_MAX,
                    j ? grid[i][j - 1] : INT_MAX);
            }
        }
        return grid[n - 1][m - 1];
    }
};
