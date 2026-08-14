class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i * i <= n; ++i) {
            int s = i * i;
            for (int j = s; j <= n; ++j) {
                dp[j] = min(1 + dp[j - s], dp[j]);
            }
        }
        return dp[n];
    }
};
