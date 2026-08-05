class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int overall = 0;
        for (int n : nums) overall ^= n;
        int position = 0;
        while (!(overall >> position & 1)) position++;
        int result1 = 0, result2 = 0;
        for (int n : nums) {
            if (n >> position & 1) result1 ^= n;
            else result2 ^= n;
        }
        return {result1, result2};
    }
};
