class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;
        int result = 1;
        for (int i = 0; i < n; ++i) {
            unordered_map<long long, int> slope;
            int duplicates = 0, best_point_line = 0;
            for (int j = i + 1; j < n; ++j) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                if (!dx && !dy) {
                    duplicates++;
                    continue;
                }
                int gcd_val = gcd(dx, dy);
                dx /= gcd_val;
                dy /= gcd_val;
                if (dx < 0 || (!dx && dy < 0)) {
                    dx = -dx;
                    dy = -dy;
                }
                long long key = ((long long)dx << 32) | (unsigned int)dy;
                slope[key]++;
                best_point_line = max(slope[key], best_point_line);
            }
            result = max(best_point_line + duplicates + 1, result);
        }
        return result;
    }
};
