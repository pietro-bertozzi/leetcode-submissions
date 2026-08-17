class Solution {
public:
    int hIndex(vector<int>& citations) {
        int p = citations.size();
        int l = 0, r = p - 1;
        int result = 0;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (citations[m] >= p - m) {
                result = p - m;
                r = m - 1;
            } else l = m + 1;
        }
        return result;
    }
};
