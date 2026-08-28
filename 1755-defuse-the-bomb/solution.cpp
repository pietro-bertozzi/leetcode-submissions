class Solution {
public:
    vector<int>& decrypt(vector<int>& code, int k) {
        int n = code.size();
        if (!k) {
            for (int i = 0; i < n; ++i) code[i] = 0;
            return code;
        }
        int l, r;
        if (k > 0) {
            l = 1;
            r = k;
        } else {
            l = n - abs(k);
            r = n - 1;
        }
        int sum = 0;
        const int BASE = 101;
        for (int i = l; i <= r; ++i) sum += code[i];
        for (int i = 0; i < n; ++i) {
            code[i] += sum * BASE;
            sum -= code[l++ % n] % BASE;
            sum += code[++r % n] % BASE;
        }
        for (int i = 0; i < n; ++i) code[i] /= BASE;
        return code;
    }
};
