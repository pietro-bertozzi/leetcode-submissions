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
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        iota(parent.begin(), parent.end(), 0);
        for (const string& e : equations) {
            if (e[1] == '=') {
                unite(e[0] - 'a', e[3] - 'a');
            }
        }
        for (const string& e : equations) {
            if (e[1] == '!' && find(e[0] - 'a') == find(e[3] - 'a')) {
                return false;
            }
        }
        return true;
    }
};
