class Solution {
public:
    void backtrack(vector<vector<int>>& result, vector<int>& candidate, int n, int k, int s) {
        if (candidate.size() == k) {
            result.push_back(candidate);
            return;
        }
        for (int i = s; i + k - candidate.size() - 1 <= n; ++i) {
            candidate.push_back(i);
            backtrack(result, candidate, n, k, i + 1);
            candidate.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> candidate;
        backtrack(result, candidate, n, k, 1);
        return result;
    }
};
