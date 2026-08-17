class Solution {
public:
    int hIndex(vector<int>& citations) {
        int p = citations.size();
        vector<int> count(p + 1, 0);
        for (int c : citations) count[min(c, p)]++;
        int cp = 0;
        for (int h = p; h >= 0; --h) {
            cp += count[h];
            if (h <= cp) return h;
        }
        return 0;
    }
};
