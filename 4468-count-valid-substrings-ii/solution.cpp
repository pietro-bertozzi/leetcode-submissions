class Solution {
public:
    long long countValidSubstrings(string s) {
        int n = s.size();
        int l = 0, a = -1, b = -1;
        long long result = 0;
        for (int r = 0; r < n; ++r) {
            if (s[r] == 'a') a = r;
            else if (s[r] == 'b' && a >= 0) b = a;
            else if (s[r] == 'c' && b >= 0) l = max(l, b + 1);
            result += r - l + 1;
        }
        return result;
    }
};
