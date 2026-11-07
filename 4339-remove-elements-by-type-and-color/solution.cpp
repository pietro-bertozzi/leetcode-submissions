class Solution {
public:
    bool canRemoveAll(vector<int>& types, vector<int>& colors, vector<int>& groupSize) {
        int n = types.size();
        stack<tuple<int, int, int>> s;
        for (int i = 0; i < n; ++i) {
            if (groupSize[types[i]] == 1) continue;
            if (s.empty()) s.push({types[i], colors[i], 1});
            else {
                auto [t, c, q] = s.top();
                if (t != types[i] || c != colors[i]) {
                    s.push({types[i], colors[i], 1});
                } else {
                    s.pop();
                    if (++q < groupSize[types[i]]) {
                        s.push({t, c, q});
                    }
                }
            }
        }
        return s.empty();
    }
};
