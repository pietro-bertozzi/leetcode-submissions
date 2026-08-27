class Solution {
public:
    int smallestNumber(int n) {
        return (1U << (32 - __builtin_clz(n))) - 1;
    }
};
