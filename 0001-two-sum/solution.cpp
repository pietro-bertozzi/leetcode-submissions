class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int complement = target - nums[i];
            if (m.count(complement) && m[complement] != i) {
                return {i, m[complement]};
            }
            m[nums[i]] = i;
        }
        return {};
    }
};
