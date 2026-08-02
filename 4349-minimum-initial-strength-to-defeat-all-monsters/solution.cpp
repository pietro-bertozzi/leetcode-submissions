class Solution {
public:
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        int n = monsters.size() - 1;
        vector<long long> diff(n + 1, 0);
        for (const auto &b : boosts) {
            if (b[0]) diff[b[0] - 1] -= b[2];
            diff[b[1]] += b[2];
        }
        long long bonus = diff[n];
        while (n >= 0 && monsters[n] <= bonus) if (--n >= 0) bonus += diff[n];
        return accumulate(monsters.begin(), monsters.begin() + n + 1, 0LL) - (n < 0 ? 0 : bonus);
    }
};
