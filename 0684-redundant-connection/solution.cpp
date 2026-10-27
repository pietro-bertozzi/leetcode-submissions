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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
        for (auto& e : edges) {
            if (find(e[0]) == find(e[1])) {
                return e;
            }
            unite(e[0], e[1]);
        }
        return {};
    }
};
