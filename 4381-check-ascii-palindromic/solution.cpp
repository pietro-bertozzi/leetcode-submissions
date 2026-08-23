class Solution {
public:
    bool isPalindromic(string s) {
        string bs = "";
        for (char c : s) bs += bitset<8>(c).to_string();
        int n = bs.size();
        int l = 0, r = n - 1;
        while (l < r) if (bs[l++] != bs[r--]) return false;
        return true;
    }
};
