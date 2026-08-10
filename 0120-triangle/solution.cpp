class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                triangle[i][j] += min(
                    j < i ? triangle[i - 1][j] : INT_MAX,
                    j ? triangle[i - 1][j - 1] : INT_MAX);
            }
        }
        int result = triangle[n - 1][0];
        for (int j = 1; j < n; ++j) result = min(triangle[n - 1][j], result);
        return result;
    }
};
