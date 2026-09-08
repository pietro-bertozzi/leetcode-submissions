class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_set<int> s(nums1.begin(), nums1.end());
        for (int n : nums2) {
            if (s.contains(n)) {
                result.push_back(n);
                s.erase(n);
            }
        }
        return result;
    }
};
