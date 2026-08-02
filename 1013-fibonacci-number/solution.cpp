class Solution {
public:
    int fib(int n) {
        if (n < 2) return n;
        int one = 0, two = 1;
        for (int i = 1; i < n; ++i) {
            int next = two + one;
            one = two;
            two = next;
        }
        return two;
    }
};
