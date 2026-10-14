class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> degree(n, 0);
        vector<vector<bool>> connected(n, vector<bool>(n, false));
        for (const auto& road : roads) {
            int u = road[0], v = road[1];
            degree[u]++, degree[v]++;
            if (u < v) connected[u][v] = true;
            else connected[v][u] = true;
        }
        int result = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int candidate = degree[i] + degree[j];
                if (connected[i][j]) candidate--;
                result = max(candidate, result);
            }
        }
        return result;
    }
};
