
class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size(), n = grid[0].size();
        int startR = 0, startC = 0;
        int k = 0;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == '@') {
                    startR = r;
                    startC = c;
                }
                if (grid[r][c] >= 'a' && grid[r][c] <= 'f') {
                    k++;
                }
            }
        }
        int target = (1 << k) - 1;
        queue<array<int, 3>> q;
        q.push({startR, startC, 0});
        vector<vector<vector<bool>>> visited(
            m, vector<vector<bool>>(
                n, vector<bool>(target + 1, false)
            )
        );
        visited[startR][startC][0] = true;
        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};
        int result = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [r, c, keys] = q.front();
                q.pop();
                if (keys == target) return result;
                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                    if (grid[nr][nc] == '#') continue;
                    int newKeys = keys;
                    if (grid[nr][nc] >= 'a' && grid[nr][nc] <= 'f') {
                        newKeys |= (1 << (grid[nr][nc] - 'a'));
                    }
                    if (grid[nr][nc] >= 'A' && grid[nr][nc] <= 'F') {
                        if (!(keys & 1 << (grid[nr][nc] - 'A'))) continue;
                    }
                    if (visited[nr][nc][newKeys]) continue;
                    visited[nr][nc][newKeys] = true;
                    q.push({nr, nc, newKeys});
                }
            }
            result++;
        }
        return -1;
    }
};

