class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int n = sequence.size(), m = word.size();
        vector<int> dp(n + 1, 0);
        int result = 0;
        for (int i = m; i <= n; ++i) {
            if (sequence.substr(i - m, m) == word) {
                dp[i] = dp[i - m] + 1;
                result = max(result, dp[i]);
            }
        }
        return result;
}
};
