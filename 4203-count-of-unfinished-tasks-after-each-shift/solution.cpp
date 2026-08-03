class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n = tasks.size(), m = shifts.size();
        vector<long long> prefix(n);
        prefix[0] = tasks[0];
        for (int i = 1; i < n; ++i) prefix[i] = prefix[i - 1] + tasks[i];
        long long total_work = prefix[n - 1];
        long long current_work = 0;
        vector<int> result;
        result.reserve(m);
        for (int j = 0; j < m; ++j) {
            current_work += shifts[j];
            if (current_work >= total_work) {
                result.push_back(0);
                current_work = 0;
            } else {
                int completed = upper_bound(prefix.begin(), prefix.end(), current_work) - prefix.begin();
                result.push_back(n - completed);
            }
        }
        return result;
    }
};
