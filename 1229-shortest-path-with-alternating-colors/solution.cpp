class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<vector<int>>> graph(2, vector<vector<int>>(n));
        for (auto& e : redEdges) graph[0][e[0]].push_back(e[1]);
        for (auto& e : blueEdges) graph[1][e[0]].push_back(e[1]);
        vector<int> result(n, -1);
        result[0] = 0;
        queue<pair<int, int>> q;
        q.push({0, 0});
        q.push({1, 0});
        vector<vector<bool>> visited(2, vector<bool>(n, false));
        visited[0][0] = visited[1][0] = true;
        int dist = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [last, node] = q.front();
                q.pop();
                if (result[node] < 0) result[node] = dist;
                int next = 1 - last;
                for (int n : graph[next][node]) {
                    if (!visited[next][n]) {
                        visited[next][n] = true;
                        q.push({next, n});
                    }
                }
            }
            dist++;
        }
        return result;
    }
};
