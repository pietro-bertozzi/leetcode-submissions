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
        if (root_i < root_j) {
            parent[root_j] = root_i;
        } else if (root_i > root_j) {
            parent[root_i] = root_j;
        }
    }

public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        parent.resize(26);
        iota(parent.begin(), parent.end(), 0);
        int n = s1.length();
        for (int i = 0; i < n; ++i) {
            unite(s1[i] - 'a', s2[i] - 'a');
        }
        string result = "";
        for (char c : baseStr) {
            result.push_back(find(c - 'a') + 'a');
        }
        return result;
    }
};
