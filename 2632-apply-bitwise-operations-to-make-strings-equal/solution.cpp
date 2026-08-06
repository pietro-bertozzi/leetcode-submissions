class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        string t = target;
        if (s == t) return true;
        int n = s.length() - 1;
        int sb = 0, tb = 0;
        for (char c : s) sb = (sb << 1) | (c - '0');
        for (char c : t) tb = (tb << 1) | (c - '0');
        return sb && tb;
    }
};
