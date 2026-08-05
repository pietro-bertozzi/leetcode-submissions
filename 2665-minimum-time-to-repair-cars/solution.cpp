class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long max_val = *max_element(ranks.begin(), ranks.end());
        long long l = 1, r = max_val * (long long) cars * cars;
        long long result = r;
        while (l <= r) {
            long long m = l + (r - l) / 2;
            long long f = 0;
            for (int r : ranks) {
                f += sqrt(m / r);
            }
            if (f >= cars) {
                result = m;
                r = m - 1;
            } else l = m + 1;
        }
        return result;
    }
};
