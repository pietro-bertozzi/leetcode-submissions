class Solution {
public:
    vector<string> readBinaryWatch(int k) {
        if (!k) return {"0:00"};
        if (k > 8) return {};
        vector<string> result;
        int q = (1 << k) - 1;
        while (q < (1 << 10)) {
            int h = q >> 6;
            int m = q & 63;
            string time = (h > 11 || m > 59) ? "" :
            to_string(h) + ":" + (m < 10 ? "0" : "") + to_string(m);
            if (!time.empty()) result.push_back(time);
            int r = q & -q;
            int n = q + r;
            q = (((n ^ q) >> 2) / r) | n;
        }
        return result;
    }
};

