class Solution {
private:
    int groups;
    vector<int> parent;

    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }

    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            groups--;
            parent[root_i] = root_j;
        }
    }

    bool similar(const string& a, const string& b) {
        int diff = 0;
        for (int i = 0; i < a.length(); ++i) {
            if (a[i] != b[i] && ++diff > 2) return false;
        }
        return diff == 0 || diff == 2;
    }

public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        groups = n;
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (similar(strs[i], strs[j])) {
                    unite(i, j);
                }
            }
        }
        return groups;
    }
};
