class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        long long result = 0;
        int n = nums.size();
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                long long product = (long long) nums[i] * nums[j];
                long long g = gcd(nums[i], nums[j]);
                long long candidate = product / (g * g);
                result = max(candidate, result);
            }
        }
        return result;
    }
};
