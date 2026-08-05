class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int bit = 0; bit < 32; ++bit) {
            int ones = 0;
            for (int n : nums) {
                if (n >> bit & 1) {
                    ones++;
                }
            }
            if (ones % 3) {
                result |= 1U << bit;
            }
        }
        return result;
    }
};
