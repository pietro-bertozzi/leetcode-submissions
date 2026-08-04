class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        auto [min_it, max_it] = minmax_element(nums.begin(), nums.end());
        int max_val = *max_it, min_val = *min_it;
        unordered_set<int> seen(nums.begin(), nums.end());
        vector<int> result;
        for (int i = min_val + 1; i < max_val; ++i) {
            if (seen.find(i) == seen.end()) {
                result.push_back(i);
            }
        }
        return result;
    }
};
