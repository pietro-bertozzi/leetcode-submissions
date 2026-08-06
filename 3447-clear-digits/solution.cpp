class Solution {
public:
    string clearDigits(string s) {
        string result;
        vector<char> st;
        for (char c : s) {
            if (st.size() && c <= '9' && st.back() > '9') st.pop_back();
            else st.push_back(c);
        }
        return string(st.begin(), st.end());
    }
};
