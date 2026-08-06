class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> f(26, 0);
        for (auto& word : words) {
            for (char c : word) {
                f[c - 'a']++;
            }
        }
        int n = words.size();
        for (int fi : f) if (fi % n) return false;
        return true;
    }
};
