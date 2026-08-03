class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, z = 0, result = 0;
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            if (!nums[i]) z++;
            while (z > k) if (!nums[l++]) z--;
            result = max(result, i - l + 1);
        }
        return result;
    }
};
