class Solution {
public:
    string reverseWords(string s) {
        int index = s.length() - 1;
        string result = "";
        result.reserve(s.length());
        while (index >= 0) {
            while (index >= 0 && s[index] == ' ') index--;
            if (index < 0) break;
            int end = index;
            while (index >= 0 && s[index] != ' ') index--;
            if (!result.empty()) result += " ";
            result += s.substr(index + 1, end - index);
        }
        return result;
    }
};
