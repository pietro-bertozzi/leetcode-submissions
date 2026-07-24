class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int p = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i]) {
                if (i != p) swap(nums[i], nums[p]);
                p++;
            }
        }
    }
};

