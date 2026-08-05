class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if ((m == n - 1 || nums[m] > nums[m + 1]) &&
                (m == 0 || nums[m] > nums[m - 1])) return m;
            else if (m == n - 1 || nums[m] > nums[m + 1]) r = m - 1;
            else l = m + 1;
        }
        return 0;
    }
};
