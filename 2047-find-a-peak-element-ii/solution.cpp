class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int k = mat.size(), n = mat[0].size();
        int l = 0;
        int r = n - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            int maxr = 0;
            for (int i = 0; i < k; ++i) {
                if (mat[i][m] > mat[maxr][m]) {
                    maxr = i;
                }
            }
            if ((m == 0 || mat[maxr][m] > mat[maxr][m - 1]) &&
                (m == n - 1 || mat[maxr][m] > mat[maxr][m + 1])) return {maxr, m};
            else if (m == n - 1 || mat[maxr][m + 1] > mat[maxr][m]) l = m + 1;
            else r = m - 1;
        }
        return {};
    }
};
