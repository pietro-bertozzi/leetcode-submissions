class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int result = nums[0], count = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (!count) result = nums[i];
            count += nums[i] == result ? 1 : -1;
        }
        return result;
    }
};

