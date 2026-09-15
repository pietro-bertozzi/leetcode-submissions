class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x ^ y, result = 0;
        while (z) { 
            z &= (z - 1);
            result++;
        }
        return result;
    }
};
