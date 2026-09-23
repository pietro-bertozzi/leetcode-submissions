class Solution {
public:
    int compress(vector<char>& chars) {
        int w = 0, r = 0;
        while (r < chars.size()) {
            char curr = chars[r];
            int c = 0;
            while (r < chars.size() && chars[r] == curr) {
                r++;
                c++;
            }
            chars[w++] = curr;
            if (c > 1) {
                for (char n : to_string(c)) {
                    chars[w++] = n;
                }
            }
        }
        return w;
    }
};
