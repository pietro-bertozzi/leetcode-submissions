class Solution {
public:
    int countValidPrefixes(string s) {
        int result = 0;
        unordered_map<int,int> valid;
        valid[0] = valid[1] = 0;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            valid[(s[i]) - '0']++;
            if (abs(valid[0] - valid[1]) < 2) result++;
        }
        return result;
    }
};
