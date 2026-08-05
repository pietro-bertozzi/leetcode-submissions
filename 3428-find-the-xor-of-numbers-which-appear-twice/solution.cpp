class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        long mask = 0;
        int result = 0;
        for (int n : nums) {
            if (mask >> n & 1) result ^= n;
            else mask |= 1LL << n;
        }
        return result;
    }
};
