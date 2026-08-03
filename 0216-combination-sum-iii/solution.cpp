class Solution {
private:
    void backtrack(int k, int i, int t, vector<int>& candidate, vector<vector<int>>& result) {
        if (candidate.size() == k) {
            if (!t) result.push_back(candidate);
            return;
        }
        if (t < 0 || i == 10) return;
        candidate.push_back(i);
        backtrack(k, i + 1, t - i, candidate, result);
        candidate.pop_back();
        backtrack(k, i + 1, t, candidate, result);
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> candidate;
        backtrack(k, 1, n, candidate, result);
        return result;
    }
};
