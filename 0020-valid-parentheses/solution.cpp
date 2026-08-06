class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> parenthesis = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
        vector<int> result;
        for (char c : s) {
            if (parenthesis.contains(c)) result.push_back(c);
            else if (result.size() && c == parenthesis[result.back()]) result.pop_back();
            else return false;
        }
        return result.empty();
    }
};
