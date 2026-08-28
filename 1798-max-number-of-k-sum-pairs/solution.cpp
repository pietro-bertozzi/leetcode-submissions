class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int result = 0;
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l < r) {
            int s = nums[l] + nums[r];
            if (s < k) l++;
            else if (s > k) r--;
            else {
                result++;
                l++;
                r--;
            }
        }
        return result;
    }
};
