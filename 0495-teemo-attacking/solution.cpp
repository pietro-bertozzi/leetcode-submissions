class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int n = timeSeries.size();
        int result = 0, end = -1;
        for (int t : timeSeries) {
            result += duration;
            if (t <= end) result -= end - t + 1;
            end = t + duration - 1;
        }
        return result;
    }
};
