class Solution {
private:
    long long gd(int i, const vector<int>& parent, vector<long long>& d) {
        if (i == -1) return 0;
        if (d[i]) return d[i];
        return d[i] = gd(parent[i], parent, d) + 1;
    }
    
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        long long w = 0;
        int n = nums.size();
        long long h = 0;
        vector<long long> d(n, 0);
        for (int i = 0; i < n; ++i) h = max(gd(i, parent, d), h);
        for (int i = 0; i < n; ++i) w += (long long) nums[i] * (h - d[i] + 1);
        return w;
    }
};
