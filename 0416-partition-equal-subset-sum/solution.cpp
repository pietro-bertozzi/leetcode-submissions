class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int tot = accumulate(nums.begin(), nums.end(), 0);
        if (tot % 2 != 0) return false;
        int target = tot / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int num : nums) {
            for (int t = target; t >= num; --t) {
                dp[t] = dp[t] || dp[t - num];
            }
        }
        return dp[target];
    }
};
