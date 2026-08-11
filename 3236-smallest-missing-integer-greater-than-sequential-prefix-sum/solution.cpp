class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int i = 0, prev = -1, prefix = 0;
        while (i < n && (prev < 0 || nums[i] == prev + 1)) {
            prev = nums[i];
            prefix += nums[i++];
        }
        unordered_set<int> s(nums.begin(), nums.end());
        while (s.contains(prefix)) prefix++;
        return prefix;
    }
};
