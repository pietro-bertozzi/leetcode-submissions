class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int i = a.length() - 1;
        int j = b.length() - 1;
        int c = 0;
        while (i >= 0 || j >= 0 || c) {
            int s = c;
            if (i >= 0) s += a[i--] - '0';
            if (j >= 0) s += b[j--] - '0';
            c = s / 2;
            result.push_back((s % 2) + '0');
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
