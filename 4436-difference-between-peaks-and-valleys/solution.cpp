class Solution {
public:
    int peakValleyDifference(vector<int>& nums) {
        int result = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int v = nums[i];
            if ((i && v > nums[i - 1]) && ((i != n - 1) && v > nums[i + 1])) result += v;
            if ((i && v < nums[i - 1]) && ((i != n - 1) && v < nums[i + 1])) result -= v;
        }
        return result;
    }
};
