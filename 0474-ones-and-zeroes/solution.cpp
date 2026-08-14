class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
        for (string s: strs) {
            int zeros = 0, ones = 0;
            for (char c : s) {
                if (c - '0') ones++;
                else zeros++;
            }
            for (int j = m; j >= zeros; --j) {
                for (int i = n; i >= ones; --i) {
                    dp[j][i] = max(1 + dp[j - zeros][i - ones], dp[j][i]);
                }
            }
        }
        return dp[m][n];
    }
};
