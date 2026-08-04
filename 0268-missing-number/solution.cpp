class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result = 0;
        for (int n : nums) result ^= n;
        for (int i = 0; i < nums.size() + 1; ++i) result ^= i;
        return result;
    }
};
