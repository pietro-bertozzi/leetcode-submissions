class Solution {
public:
    int tribonacci(int n) {
        if (n < 2) return n;
        int one = 0, two = 1, three = 1;
        for (int i = 2; i < n; ++i) {
            int next = three + two + one;
            one = two;
            two = three;
            three = next;
        }
        return three;
    }
};
