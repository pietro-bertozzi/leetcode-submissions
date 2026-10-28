class Solution {
private:
    unordered_map<string, string> parent;

    string find(const string& s) {
        if (parent.find(s) == parent.end()) parent[s] = s;
        if (parent[s] == s) return s;
        return parent[s] = find(parent[s]);
    }

    void unite(const string& i, const string& j) {
        string root_i = find(i);
        string root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
        }
    }

public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> email_to_name;
        for (const auto& a : accounts) {
            for (size_t i = 1; i < a.size(); ++i) {
                unite(a[1], a[i]);
                email_to_name[a[i]] = a[0];
            }
        }
        unordered_map<string, vector<string>> groups;
        for (const auto& p : email_to_name) {
            groups[find(p.first)].push_back(p.first);
        }
        vector<vector<string>> result;
        for (auto& g : groups) {
            sort(g.second.begin(), g.second.end());
            vector<string> merged;
            merged.push_back(email_to_name[g.first]);
            merged.insert(merged.end(), g.second.begin(), g.second.end());
            result.push_back(merged);
        }
        return result;
    }
};
