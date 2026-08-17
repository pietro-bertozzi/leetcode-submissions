class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        int result = nums[0];
        while (l <= r) {
            if (nums[l] < nums[r]) {
                result = min(result, nums[l]);
                break;
            }
            int m = l + (r - l) / 2;
            result = min(nums[m], result);
            if (nums[l] <= nums[m]) l = m + 1;
            else r = m - 1;
        }
        return result;
    }
};
