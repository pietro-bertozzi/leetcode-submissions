class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = t.size(), p = 0;
        for (int si : s) {
            while (p < n && si != t[p]) p++;
            if (p == n) return false;
            p++;
        }
        return true;
    }
};
