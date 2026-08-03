class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.length(), result = 0;
        string vowels = "aeiou";
        for (int i = 0; i < k; ++i) {
            if (vowels.contains(s[i])) result++;
        }
        int candidate = result;
        for (int i = k; i < n; ++i) {
            if (vowels.contains(s[i])) candidate++;
            if (vowels.contains(s[i - k])) candidate--;
            result = max(candidate, result);
        }
        return result;
    }
};
