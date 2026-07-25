class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (!n) return true;
        int nf = flowerbed.size();
        for (int i = 0; i < nf; ++i) {
            if (!flowerbed[i] &&
                (!i || !flowerbed[i - 1]) &&
                (i == nf - 1 || !flowerbed[i + 1]))
            {
                flowerbed[i] = 1;
                n--;
            }
            if (!n) return true;
        }
        return false;
    }
};
