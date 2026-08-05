class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> sorted = arr;
        unordered_map<int, int> ranks;
        sort(sorted.begin(), sorted.end());
        int r = 0;
        for (int s : sorted) {
            if (ranks.find(s) == ranks.end()) {
                ranks[s] = ++r;
            }
        }
        for (int i = 0; i < n; ++i) {
            arr[i] = ranks[arr[i]];
        }
        return arr;
    }
};
