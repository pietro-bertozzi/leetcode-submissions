class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l = 0, r = 0, zeros = 0;
        for (; r < nums.size(); ++r) {
            if (!nums[r]) zeros++;
            if (zeros > 1 && !nums[l++]) zeros--;
        }
        return r - l - 1;
    }
};
