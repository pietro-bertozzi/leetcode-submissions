class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> dp(m + 1, 0);
        int best = 0, prev = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int temp = dp[j + 1];
                if (matrix[i][j] == '1') {
                    dp[j + 1] = 1 + min({dp[j], dp[j + 1], prev});
                    best = max(dp[j + 1], best);
                } else dp[j + 1] = 0;
                prev = temp;
            }
        }
        return best * best;
    }
};
