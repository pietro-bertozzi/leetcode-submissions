class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 0, r = num;
        while (l <= r) {
            long long m = l + (r - l) / 2;
            long long f = m * m;
            if (f < num) l = m + 1;
            else if (f > num) r = m - 1;
            else return true;
        }
        return false;
    }
};
