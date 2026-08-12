class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() < nums2.size()) swap(nums1, nums2);
        int n = nums1.size(), m = nums2.size();
        vector<int> dp(m + 1);
        for (int i = 1; i <= n; ++i) {
            int prev = 0;
            for (int j = 1; j <= m; ++j) {
                int temp = dp[j];
                if (nums1[i - 1] == nums2[j - 1]) dp[j] = 1 + prev;
                else dp[j] = max(dp[j], dp[j - 1]);
                prev = temp;
            }
        }
        return dp[m];
    }
};
