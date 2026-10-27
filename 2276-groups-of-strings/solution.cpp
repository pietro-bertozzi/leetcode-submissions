
class Solution {
private:
    int groups, best;
    vector<int> parent;
    vector<int> dimension;

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
            dimension[root_j] += dimension[root_i];
            best = max(best, dimension[root_j]);
        }
    }

public:
    vector<int> groupStrings(vector<string>& words) {
        int n = words.size();
        groups = n, best = 1;
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        dimension.assign(n, 1);
        unordered_map<int, int> mask_to_id;
        unordered_map<int, int> deleted_to_id;
        for (int i = 0; i < n; ++i) {
            int mask = 0;
            for (char c : words[i]) {
                mask |= (1 << (c - 'a'));
            }
            if (mask_to_id.count(mask)) {
                unite(i, mask_to_id[mask]);
                continue;
            }
            mask_to_id[mask] = i;
            for (int c = 0; c < 26; ++c) {
                int bit = 1 << c;
                int neighbor = mask ^ bit;
                if (mask_to_id.count(neighbor)) {
                    unite(i, mask_to_id[neighbor]);
                }
                if (mask & bit) {
                    int removed = mask ^ bit;
                    if (deleted_to_id.count(removed)) {
                        unite(i, deleted_to_id[removed]);
                    } else {
                        deleted_to_id[removed] = i;
                    }
                }
            }
        }
        return {groups, best};
    }
};

