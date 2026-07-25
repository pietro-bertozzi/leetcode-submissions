class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int one = 0, two = 0;
        int n = cost.size();
        for (int i = 2; i < n; ++i) {
            int temp = two;
            two = min(two + cost[i - 1], one + cost[i - 2]);
            one = temp;
        }
        return min(two + cost[n - 1], one + cost[n - 2]);
    }
};
