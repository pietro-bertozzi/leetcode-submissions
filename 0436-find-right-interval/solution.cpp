class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int, int>> starts(n);
        for (int i = 0; i < n; ++i) starts[i] = {intervals[i][0], i};
        sort(starts.begin(), starts.end());
        vector<int> result(n, -1);
        for (int i = 0; i < n; ++i) {
            auto it = lower_bound(starts.begin(), starts.end(), make_pair(intervals[i][1], -1));
            if (it != starts.end()) result[i] = it->second;
        }
        return result;
    }
};
