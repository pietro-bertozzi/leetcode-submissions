class Solution {
public:
    int rob(vector<int>& nums) {
        int h1 = 0, h2 = 0;
        for (int h : nums) {
            int next = max(h + h1, h2);
            h1 = h2;
            h2 = next;
        }
        return h2;
    }
};
