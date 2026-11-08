class Solution {
private:
    void update(unordered_map<int, int>& f, int& diff, int x, int d) {
        int before = f[x];
        int after = before + d;
        if (!before && after) diff++;
        if (before && !after) diff--;
        f[x] = after;
    }
    
public:
    int countSuffix(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        vector<bool> sorted(n, true);
        for (int i = n - 2; i >= 0; --i) {
            sorted[i] = sorted[i + 1] && target[i] >= target[i + 1];
        }
        unordered_map<int, int> f;
        int diff = 0;
        for(int i = 0; i < n; ++i) {
            update(f, diff, nums[i], 1);
            update(f, diff, target[i], -1);
        }
        int result = 0;
        bool same_prefix = true;
        for (int i = 0; i < n; ++i) {
            if (same_prefix && sorted[i] && !diff) result++;
            update(f, diff, nums[i], -1);
            update(f, diff, target[i], 1);
            if (nums[i] != target[i]) same_prefix = false;
        }
        return result;
    }
};
