class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int result = 0, x, y;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            x = 0, y = 0;
            for (int j = i; j < n; ++j) {
                if (nums[j] % 2) y++;
                else x++;
                if (x * b <= a * y) result++;
            }
        }
        return result;
    }
};
