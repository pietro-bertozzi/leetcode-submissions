class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> f;
        int result = -1;
        int best = 0;
        for (int n : nums) {
            if (n % 2) continue;
            int candidate = ++f[n];
            if (candidate > best || (candidate == best && n < result)) {
                best = candidate;
                result = n;
            }
        }
        return result;
    }
};
