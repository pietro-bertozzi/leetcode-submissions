class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > sum || (target + sum) % 2) return 0;
        int subset_target = (target + sum) / 2;
        vector<int> dp(subset_target + 1, 0);
        dp[0] = 1;
        for (int num : nums) {
            for (int w = subset_target; w >= num; --w) {
                dp[w] += dp[w - num];
            }
        }
        return dp[subset_target];
    }
};
