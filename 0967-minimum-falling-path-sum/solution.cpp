class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                matrix[i][j] += min ({ matrix[i - 1][j],
                    j ? matrix[i - 1][j - 1] : INT_MAX,
                    j < m - 1 ? matrix[i - 1][j + 1] : INT_MAX});
            }
        }
        int result = matrix[n - 1][0];
        for (int j = 1; j < m; ++j) result = min(matrix[n - 1][j], result);
        return result;
    }
};
