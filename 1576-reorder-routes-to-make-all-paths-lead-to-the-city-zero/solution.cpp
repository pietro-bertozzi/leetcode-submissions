class Solution {
private:
    int result;
    vector<bool> visited;
    vector<vector<pair<int, int>>> graph;

    void dfs(int node) {
        visited[node] = true;
        for (const auto& n : graph[node]) {
            if (!visited[n.first]) {
                result += n.second;
                dfs(n.first);
            }
        }
    }

public:
    int minReorder(int n, vector<vector<int>>& connections) {
        result = 0;
        visited.assign(n, false);
        graph.assign(n, vector<pair<int, int>>());
        for (const auto& c : connections) {
            graph[c[0]].push_back({c[1], 1});
            graph[c[1]].push_back({c[0], 0});
        }
        dfs(0);
        return result;
    }
};
