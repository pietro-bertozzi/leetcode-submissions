class Solution {
public:
    int arrangeCoins(int n) {
        long l = 1, r = n;
        while (l <= r) {
            long m = l + (r - l) / 2;
            long coins = m * (m + 1) / 2;
            if (coins <= n) l = m + 1;
            else r = m - 1;
        }
        return r;
    }
};
