class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int s = nums.size();
        int result = 0;
        for (int i = 0; i < 32; ++i) {
            int ones = 0;
            for (int n : nums) ones += (n >> i) & 1;
            result += (s - ones) * ones;
        }
        return result;
    }
};
