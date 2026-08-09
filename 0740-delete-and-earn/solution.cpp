class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        int best = *max_element(nums.begin(), nums.end());
        vector<int> points(best + 1, 0);
        for (int c : nums) points[c] += c;
        int p1 = 0, p2 = 0;
        for (int p : points) {
            int next = max(p + p1, p2);
            p1 = p2;
            p2 = next;
        }
        return p2;
    }
};
