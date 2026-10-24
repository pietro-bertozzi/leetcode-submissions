class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        int l = 0;
        long long result = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] < minK || nums[i] > maxK) {
                long long par = i - l;
                result += (par + 1) * par / 2;
                l = i + 1;
            }
        }
        long long par = n - l;
        if (l < n) result += (par + 1) * par / 2;
        return result;
    }
};
