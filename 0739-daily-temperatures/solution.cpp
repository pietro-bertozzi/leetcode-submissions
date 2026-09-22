class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);
        vector<int> mono;
        mono.reserve(n);
        for (int i = 0; i < n; ++i) {
            while (!mono.empty() && temperatures[mono.back()] < temperatures[i]) {
                int p = mono.back();
                mono.pop_back();
                result[p] = i - p;
            }
            mono.push_back(i);
        }
        return result;
    }
};
