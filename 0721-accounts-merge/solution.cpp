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
        unordered_map<string, string> emailToName;

        for (const auto& account : accounts) {
            const string& name = account[0];
            const string& firstEmail = account[1];

            for (size_t i = 1; i < account.size(); ++i) {
                unite(firstEmail, account[i]);
                emailToName[account[i]] = name;
            }
        }

        unordered_map<string, vector<string>> emailGroups;
        for (const auto& pair : emailToName) {
            const string& email = pair.first;
            emailGroups[find(email)].push_back(email);
        }

        vector<vector<string>> result;
        for (auto& pair : emailGroups) {
            vector<string>& emails = pair.second;
            sort(emails.begin(), emails.end());
            
            vector<string> accountMerged;
            accountMerged.push_back(emailToName[pair.first]);
            accountMerged.insert(accountMerged.end(), emails.begin(), emails.end());
            
            result.push_back(accountMerged);
        }

        return result;
    }
};
