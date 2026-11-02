class Solution {
public:
    int dfs(int id, const vector<vector<int>>& subordinates, const vector<int>& informTime) {
        if (subordinates[id].empty()) return 0;
        int best = 0;
        for (int i = 0; i < subordinates[id].size(); ++i) {
            int candidate = dfs(subordinates[id][i], subordinates, informTime);
            best = max(candidate, best);
        }
        return informTime[id] + best;
    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> subordinates(n);
        for (int i = 0; i < n; ++i) {
            if (manager[i] > -1) {
                subordinates[manager[i]].push_back(i);
            }
        }
        return dfs(headID, subordinates, informTime);
    }
};
