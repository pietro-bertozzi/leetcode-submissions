class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> incoming(n, false);
        for (const auto& e : edges) {
            incoming[e[1]] = true;
        }
        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (!incoming[i]) {
                result.push_back(i);
            }
        }
        return result;
    }
};
