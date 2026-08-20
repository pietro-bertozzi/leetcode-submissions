class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        int MOD = 1e9 + 7;
        sort(nums.begin(), nums.end());
        vector<int> pow2(n, 1);
        for (int i = 1; i < n; ++i) pow2[i] = (pow2[i - 1] * 2) % MOD;
        int l = 0, r = n - 1, c = 0;
        while (l <= r) {
            if (nums[l] + nums[r] <= target) c = (c + pow2[r - l++]) % MOD;
            else r--;
        }
        return c;
    }
};
