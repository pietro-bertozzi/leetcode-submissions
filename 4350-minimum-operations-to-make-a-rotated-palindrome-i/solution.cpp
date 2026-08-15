class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int best = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int candidate = i;
            for (int j = 0; j < n / 2; ++j) {
                int ca = s[(i + j) % n] - 'a';
                int cb = s[(i - j + n - 1) % n] - 'a';
                int mo = INT_MAX;
                for (int k = 0; k < 26; ++k) {
                    mo = min(((k - ca + 26) % 26) + ((k - cb + 26) % 26), mo);
                }
                candidate += mo;
            }
            best = min(candidate, best);
        }
        return best;
    }
};
