class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> result;
        result.push_back(first);
        int d = first;
        for (int e : encoded) {
            d ^= e;
            result.push_back(d);
        }
        return result;
    }
};


