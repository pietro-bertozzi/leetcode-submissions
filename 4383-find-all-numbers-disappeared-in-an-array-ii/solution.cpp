class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        vector<vector<int>> result;
        int candidate = lower;
        for (int n : nums) {
            if (n < lower) continue;
            if (n > upper) break;
            if (n > candidate) result.push_back({candidate, n - 1});
            candidate = n + 1;
        }
        if (candidate <= upper) result.push_back({candidate, upper});
        return result;
    }
};
