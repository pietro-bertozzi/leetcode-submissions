class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) swap(nums1, nums2);
        int n = nums1.size(), m = nums2.size();
        int lh = (n + m) / 2;
        int l = 0, r = n;
        while (l <= r) {
            int m1 = l + (r - l) / 2;
            int m2 = lh - m1;
            int l1 = (m1 == 0) ? INT_MIN : nums1[m1 - 1];
            int r1 = (m1 == n) ? INT_MAX : nums1[m1];
            int l2 = (m2 == 0) ? INT_MIN : nums2[m2 - 1];
            int r2 = (m2 == m) ? INT_MAX : nums2[m2];
            if (l2 > r1) l = m1 + 1;
            else if (l1 > r2) r = m1 - 1;
            else {
                if ((m + n) % 2) return min(r1, r2);
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            }
        }
        return 0.0;
    }
};
