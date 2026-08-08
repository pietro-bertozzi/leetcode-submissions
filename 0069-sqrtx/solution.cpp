class Solution {
public:
    int mySqrt(int x) {
        long long l = 0, r = x, result = 0;
        while (l <= r) {
            long long m = l + (r - l) / 2;
            long long f = m * m;
            if (f <= x) {
                l = m + 1;
                result = m;
            } else r = m - 1;
        }
        return result;
    }
};
