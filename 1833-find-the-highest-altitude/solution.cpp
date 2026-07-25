class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int h = 0, best = 0;
        for (int g : gain) {
            h += g;
            best = max(h, best);
        }
        return best;
    }
};
