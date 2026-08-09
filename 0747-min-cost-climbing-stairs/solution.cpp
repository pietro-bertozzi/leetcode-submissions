class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int one = 0, two = 0;
        for (int i = 2; i < n; ++i) {
            int next = min(two + cost[i - 1], one + cost[i - 2]);
            one = two;
            two = next;
        }
        return min(two + cost[n - 1], one + cost[n - 2]);
    }
};
