class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int best = 0;
        while (l < r) {
            int candidate = r - l;
            if (height[l] > height[r]) candidate *= height[r--];
            else candidate *= height[l++];
            best = max(candidate, best);
        }
        return best;        
    }
};
