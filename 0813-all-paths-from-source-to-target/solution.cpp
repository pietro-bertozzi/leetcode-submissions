class Solution {
private:
    void backtrack(int curr, int target, const vector<vector<int>>& graph, vector<int>& candidate, vector<vector<int>>& result) {
        candidate.push_back(curr);
        if (curr == target) {
            result.push_back(candidate);
        } else for (int n : graph[curr]) {
            backtrack(n, target, graph, candidate, result);
        }
        candidate.pop_back();
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        vector<int> candidate;
        backtrack(0, graph.size() - 1, graph, candidate, result);
        return result;
    }
};
