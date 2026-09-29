class Solution {
public:
    int binaryGap(int n) {
        int result = 0, lp = __builtin_ctz(n);
        n &= (n - 1);
        while (n > 0) {
            int p = __builtin_ctz(n);
            result = max(result, p - lp);
            lp = p;
            n &= (n - 1);
        }
        return result;
    }
};
