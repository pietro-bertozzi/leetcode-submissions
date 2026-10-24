class Solution {
public:
    int countMagicalPairs(string s) {
        int n = s.length();
        int result = 0;
        for (int j = 0; j < n - 1; ++j) {
            vector<int> f1(26, 0);
            vector<int> f2(26, 0);
            vector<int> fd(27, 0);
            int d1 = 0, d2 = 0;
            for (int i = j; i >= 0; --i) {
                if (!f1[s[i] - 'a']) d1++;
                f1[s[i] - 'a']++;
                fd[d1]++;
            }
            for (int k = j + 1; k < n; ++k) {
                if (!f2[s[k] - 'a']) d2++;
                f2[s[k] - 'a']++;
                result += fd[d2];
            }
        }
        return result;
    }
};
