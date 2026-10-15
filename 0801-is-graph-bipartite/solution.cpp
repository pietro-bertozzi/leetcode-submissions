class Solution {
private:
    vector<int> parent;

    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }

    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
        }
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        for (int u = 0; u < n; ++u) {
            for (int v : graph[u]) {
                if (find(u) == find(v)) return false;
                unite(graph[u][0], v);
            }
        }
        return true;
    }
};
