class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int musk = 0;
        for (int n : nums) musk |= n;
        return musk << (nums.size() - 1);
    }
};
