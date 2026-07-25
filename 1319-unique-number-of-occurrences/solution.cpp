class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> counts;
        for (int n : arr) counts[n]++;
        unordered_set<int> f;
        for (auto& [n, count] : counts) {
            if (!f.insert(count).second) return false;
        }
        return true;
    }
};
