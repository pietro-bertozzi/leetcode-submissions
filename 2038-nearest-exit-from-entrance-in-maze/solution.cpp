class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int rows = maze.size(), cols = maze[0].size();
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';
        const vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int s = 0;
        while (!q.empty()) {
            int ls = q.size();
            for (int i = 0; i < ls; ++i) {
                auto [r, c] = q.front();
                q.pop();
                for (const auto& [dr, dc] : d) {
                    int nr = r + dr;
                    int nc = c + dc;
                    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && maze[nr][nc] == '.') {
                        if (!nr || nr == rows - 1 || !nc || nc == cols - 1) return s + 1;
                        maze[nr][nc] = '+';
                        q.push({nr, nc});
                    }
                }
            }
            s++;
        }
        return -1;
    }
};
