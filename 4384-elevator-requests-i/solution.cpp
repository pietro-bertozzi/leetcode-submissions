class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int m = requests.size();
        int result = requests[0];
        for (int i = 1; i < m; ++i) {
            result += abs(requests[i] - requests[i - 1]);
        }
        return result;
    }
};
