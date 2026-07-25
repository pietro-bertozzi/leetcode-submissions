class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set s1 (nums1.begin(), nums1.end());
        unordered_set s2 (nums2.begin(), nums2.end());
        vector<int> v1, v2;
        for (int n : s1) if (!s2.count(n)) v1.push_back(n);
        for (int n : s2) if (!s1.count(n)) v2.push_back(n);
        return {v1, v2};
    }
};
