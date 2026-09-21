class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        map<vector<int>, int> rows;
        for (int r = 0; r < n; ++r) rows[grid[r]]++;
        int result = 0;
        for (int c = 0; c < n; ++c) {
            vector<int> col(n);
            for (int r = 0; r < n; ++r) col[r] = grid[r][c];
            if (rows.contains(col)) result += rows[col];
        }
        return result;
    }
};
