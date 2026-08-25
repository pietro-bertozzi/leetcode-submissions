class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int result = k;
        unordered_set<int> arr(nums.begin(), nums.end());
        while (arr.contains(result)) result += k;
        return result;
    }
};
