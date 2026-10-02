class Solution {
private:
    void dfs(int city, vector<vector<int>>& isConnected, vector<bool>& visited) {
        visited[city] = true;
        for (int n = 0; n < isConnected.size(); n++) {
            if (isConnected[city][n] && !visited[n]) {
                dfs(n, isConnected, visited);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int result = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                result++;
                dfs(i, isConnected, visited);
            }
        }
        return result;
    }
};
