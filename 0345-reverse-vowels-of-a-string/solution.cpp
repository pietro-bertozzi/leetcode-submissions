class Solution {
public:
    string reverseVowels(string s) {
        string vowels = "aeiouAEIOU";
        int l = 0, r = s.size() - 1;
        while (l < r) {
            while (l < r && !vowels.contains(s[l])) l++;
            while (l < r && !vowels.contains(s[r])) r--;
            if (l < r) swap(s[l++], s[r--]);
        }
        return s;
    }
};
