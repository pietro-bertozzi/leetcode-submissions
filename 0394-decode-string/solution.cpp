class Solution {
public:
    string decodeString(string s) {
        stack<int> ns;
        stack<string> strs;
        string currStr = "";
        int n = 0;
        for (char c : s) {
            if (isdigit(c)) n = n * 10 + (c - '0');
            else if (c == '[') {
                ns.push(n);
                strs.push(currStr);
                n = 0;
                currStr = "";
            } else if (c == ']') {
                int count = ns.top(); ns.pop();
                string prevStr = strs.top(); strs.pop();
                string repeated = "";
                for (int i = 0; i < count; ++i) repeated += currStr;
                currStr = prevStr + repeated;
            } else currStr += c;
        }
        return currStr;
    }
};
