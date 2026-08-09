class Solution {
public:
    int uniquePaths(int m, int n) {
        int s = m + n - 2;
        int k = min(m - 1, n - 1);
        long long result = 1;
        for (int i = 1; i <= k; ++i) result = result * (s - k + i) / i;
        return result;
    }
};
