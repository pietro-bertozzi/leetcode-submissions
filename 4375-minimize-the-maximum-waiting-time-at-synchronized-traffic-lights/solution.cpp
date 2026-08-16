class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int best = 0, mg = *max_element(lights.begin(), lights.end());
        for (int at : arrivalTime) {
            int r = at % period;
            int candidate = r < mg ? 0 : period - r;
            best = max(candidate, best);
        }
        return best;
    }
};
