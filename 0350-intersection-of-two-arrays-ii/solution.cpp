class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) swap(nums1, nums2);
        vector<int> result;
        unordered_map<int, int> counts;
        for (int n : nums1) counts[n]++;
        for (int n : nums2) {
            if (counts[n]) {
                result.push_back(n);
                counts[n]--;
            }
        }
        return result;
    }
};
