class Solution {
public:
    int minOperations(vector<string>& logs) {
        int result = 0;
        for (string l : logs) {
            if (result && l == "../") result--;
            else if (l[0] != '.') result++;
        }
        return result;
    }
};
