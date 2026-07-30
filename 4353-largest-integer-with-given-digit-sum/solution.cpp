class Solution {
public:
    int largestInteger(int n, int s) {
        if (n * 9 < s) return -1;
        int result = 0;
        while (s >= 9) {
            result *= 10;
            result += 9;
            n--;
            s -= 9;
        }
        if (s) {
            result *= 10;
            result += s;
            n--;
            s = 0;
        }
        if (n) result *= pow(10, n);
        return result;
    }
};
