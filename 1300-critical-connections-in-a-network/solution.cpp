class Solution {
private:
    vector<vector<int>> graph;
    vector<int> dist;
    vector<int> best;
    vector<vector<int>> result;
    int depth;

    void dfs(int u, int p) {
        dist[u] = best[u] = ++depth;
        for (int v : graph[u]) {
            if (v == p) continue;
            if (dist[v] >= 0) {
                best[u] = min(dist[v], best[u]);
                continue;
            }
            dfs(v, u);
            best[u] = min(best[v], best[u]);
            if (best[v] > dist[u]) {
                result.push_back({u, v});
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        graph.assign(n, vector<int>());
        for (const auto& conn : connections) {
            graph[conn[0]].push_back(conn[1]);
            graph[conn[1]].push_back(conn[0]);
        }
        dist.assign(n, -1);
        best.assign(n, -1);
        result.clear();
        depth = 0;
        dfs(0, -1);
        return result;
    }
};
