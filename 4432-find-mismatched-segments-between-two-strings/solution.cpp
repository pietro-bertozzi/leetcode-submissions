class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        int n = s1.size();
        vector<vector<string>> result;
        for (int i = 0; i < n; ++i) {
            if (s1[i] != s2[i]) {
                int s = i;
                while (i < n && s1[i] != s2[i]) i++; 
                result.push_back({
                    s1.substr(s, i - s),
                    s2.substr(s, i - s)
                });
            }
        }
        return result;
    }
};
