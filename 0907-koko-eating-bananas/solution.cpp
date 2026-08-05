class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int l = 1, r = *max_element(piles.begin(), piles.end());
        int result = r;
        while (l <= r) {
            int m = l + (r - l) / 2;
            long long f = 0;
            for (int p : piles){
                f += (p + m - 1) / m;
            }
            if (f <= h) {
                result = m;
                r = m - 1;
            } else l = m + 1;
        }
        return result;
    }
};
