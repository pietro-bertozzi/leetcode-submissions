class Solution {
public:
    int tribonacci(int n) {
        if (n < 2) return n;
        int one = 0, two = 1, three = 1;
        n -= 2;
        while (n--) {
            int temp = one;
            one = two;
            two = three;
            three = two + one + temp;
        }
        return three;
    }
};
