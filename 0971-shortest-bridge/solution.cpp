class Solution {
private:
    int n;
    vector<vector<bool>> visited;
    queue<pair<int, int>> beach;
    vector<pair<int, int>> d = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    void dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= n || j < 0 || j >= n || !grid[i][j] || visited[i][j]) return;
        visited[i][j] = true;
        for (const auto& dir : d) {
            int ni = i + dir.first;
            int nj = j + dir.second;
            if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
                if (!grid[ni][nj] && !visited[ni][nj]) {
                    visited[ni][nj] = true;
                    beach.push({ni, nj});
                } else if (grid[ni][nj]) dfs(grid, ni, nj);
            }
        }
    }

public:
    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        visited.assign(n, vector<bool>(n, false));
        bool found = false;
        for (int i = 0; i < n && !found; ++i) {
            for (int j = 0; j < n && !found; ++j) {
                if (grid[i][j]) {
                    dfs(grid, i, j);
                    found = true;
                }
            }
        }
        int result = 1;
        while (!beach.empty()) {
            int s = beach.size();
            for (int k = 0; k < s; ++k) {
                auto [i, j] = beach.front();
                beach.pop();
                for (const auto& dir : d) {
                    int ni = i + dir.first;
                    int nj = j + dir.second;
                    if (ni >= 0 && ni < n && nj >= 0 && nj < n && !visited[ni][nj]) {
                        if (grid[ni][nj]) return result;
                        visited[ni][nj] = true;
                        beach.push({ni, nj});
                    }
                }
            }
            result++;
        }
        return -1;
    }
};
