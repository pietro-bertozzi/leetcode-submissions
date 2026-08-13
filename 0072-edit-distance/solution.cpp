class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.size() < word2.size()) swap(word1, word2);
        int n = word1.size(), m = word2.size();
        vector<int> dp(m + 1, 0);
        for (int j = 0; j <= m; ++j) dp[j] = j;
        for (int i = 1; i <= n; ++i) {
            int prev = dp[0];
            dp[0] = i;
            for (int j = 1; j <= m; ++j) {
                int temp = dp[j];
                if (word1[i - 1] == word2[j - 1]) dp[j] = prev;
                else dp[j] = 1 + min({dp[j - 1], dp[j], prev});
                prev = temp;
            }
        }
        return dp[m];
    }
};
