class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int result = 0, end = 0, best = 0;
        for (int i = 0; i < n - 1; ++i) {
            best = max(i + nums[i], best);
            if (i == end) {
                end = best;
                result++;
            }
        }
        return result;
    }
};
