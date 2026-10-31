class Solution {
private:
    bool dfs(int node, const vector<vector<int>>& graph, vector<int>& state) {
        if (state[node] == 1) return false;
        if (state[node] == 2) return true;
        state[node] = 1;
        for (int n : graph[node]) {
            if (!dfs(n, graph, state)) {
                return false;
            }
        }
        state[node] = 2;
        return true;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> state(n, 0);
        vector<int> safe_nodes;
        for (int i = 0; i < n; ++i) {
            if (dfs(i, graph, state)) {
                safe_nodes.push_back(i);
            }
        }
        return safe_nodes;
    }
};
