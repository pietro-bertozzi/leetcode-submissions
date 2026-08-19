class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int result = 0;
        for (int i = n - 1; i > 1; i--) {
            int l = 0, r = i - 1;
            while (l < r) {
                if (nums[l] + nums[r] > nums[i]) result += r-- - l;
                else l++;
            }
        }
        return result;
    }
};

