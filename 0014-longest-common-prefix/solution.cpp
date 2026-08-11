class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        bool stop = false;
        int i = 0;
        while (!stop && i < strs[0].size()) {
            char need = strs[0][i];
            for (int j = 1; j < n; ++j) {
                if (i == strs[j].size() || strs[j][i] != need) stop = true;
            }
            if (!stop) i++;
        }
        return strs[0].substr(0, i);
    }
};
