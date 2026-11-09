
class Solution {
private:
    int dirs[8][2] = {
        {-1, 0}, {0, -1}, {0, 1}, {1, 0},
        {-1, -1}, {-1, 1}, {1, -1}, {1, 1}
    };

    bool isValid(int r, int c, int n, vector<vector<int>>& grid) {
        return r >= 0 && r < n &&
               c >= 0 && c < n &&
               !grid[r][c];
    }

public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] || grid[n-1][n-1]) return -1;
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;
        int result = 1;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [r, c] = q.front();
                q.pop();
                if (r == c && c == n - 1) return result;
                for (auto& d : dirs) {
                    int nr = r + d[0];
                    int nc = c + d[1];
                    if (isValid(nr, nc, n, grid)) {
                        grid[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }
            }
            result++;
        }
        return -1;
    }
};

