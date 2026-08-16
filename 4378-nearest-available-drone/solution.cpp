class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int n = drones.size();
        int best = INT_MAX, ibest = -1;
        for (int i = 0; i < n; ++i) {
            int candidate = abs(drones[i][0] - target[0]) + abs(drones[i][1] - target[1]);
            if (candidate <= drones[i][2] && candidate < best) {
                best = candidate;
                ibest = i;
            }
        }
        return ibest;
    }
};
