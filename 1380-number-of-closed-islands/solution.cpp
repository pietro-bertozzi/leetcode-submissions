
class Solution {
private:
    void dfs(vector<vector<int>>& grid, int i, int j, bool& touchesBorder) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j]) {
            return;
        }
        if (!i || i == m - 1 || !j || j == n - 1) {
            touchesBorder = true;
        }
        grid[i][j] = 1;
        dfs(grid, i + 1, j, touchesBorder);
        dfs(grid, i - 1, j, touchesBorder);
        dfs(grid, i, j + 1, touchesBorder);
        dfs(grid, i, j - 1, touchesBorder);
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int result = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!grid[i][j]) {
                    bool touchesBorder = false;
                    dfs(grid, i, j, touchesBorder);
                    if (!touchesBorder) {
                        result++;
                    }
                }
            }
        }
        return result;
    }
};

