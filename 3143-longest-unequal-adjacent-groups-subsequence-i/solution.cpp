class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> result;
        int n = groups.size();
        bool start = false;
        bool turn;
        for (int i = 0; i < n; ++i) {
            if (!start) {
                start = !start;
                turn = !groups[i];
                result.push_back(words[i]);
            } else if (turn == groups[i]) {
                turn = !turn;
                result.push_back(words[i]);
            }
        }
        return result;
    }
};
