class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        unordered_map<int, int> frequency;
        unordered_map<int, int> results;
        for (int p : planks) {
            frequency[p]++;
            results[p]++;
        }
        for (auto &a: frequency) {
            for (auto &b: frequency) {
                int a1 = a.first;
                int b1 = b.first;
                if (a1 == b1) results[a1 * 2] += a.second / 2;
                else if (a1 < b1) results[a1 + b1] += min(a.second, b.second);
            }
        }
        int best = 0;
        for (auto &a : results) best = max(a.second, best);
        return best;
    }
};
