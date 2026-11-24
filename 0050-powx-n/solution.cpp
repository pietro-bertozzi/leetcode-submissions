class Solution {
public:
    double myPow(double x, int n) {
        long long N = abs((long long)n);
        long double result = 1.0;
        long double base = x;
        while (N) {
            if (N & 1) result *= base;
            base *= base;
            N >>= 1;
        }
        return n < 0 ? 1.0 / result : result;
    }
};
