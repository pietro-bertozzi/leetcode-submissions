class Solution {
private:
    int xorTill(int x) {
        if (x % 4 == 0) return x;
        if (x % 4 == 1) return 1;
        if (x % 4 == 2) return x + 1;
        return 0;
    }

public:
    int xorOperation(int n, int start) {
        int s = start / 2;
        return ((xorTill(s + n - 1) ^ xorTill(s - 1)) << 1) | (n & start & 1);
    }
};
