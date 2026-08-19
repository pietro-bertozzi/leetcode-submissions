class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        sort(potions.begin(), potions.end());
        vector<int> result(n);
        for (int i = 0; i < n; ++i) {
            long long mp = (success + spells[i] - 1) / spells[i];
            auto it = lower_bound(potions.begin(), potions.end(), mp);
            result[i] = potions.end() - it;
        }
        return result;
    }
};
