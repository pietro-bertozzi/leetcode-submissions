class Solution {
private:
    vector<int> ps;
    mt19937 rng;
    uniform_int_distribution<int> dist;

public:
    Solution(vector<int>& w) {
        int sum = 0;
        for (int weight : w) {
            sum += weight;
            ps.push_back(sum);
        }
        random_device rd;
        rng = mt19937(rd());
        dist = uniform_int_distribution<int>(1, sum);
    }
    
    int pickIndex() {
        return lower_bound(ps.begin(), ps.end(), dist(rng)) - ps.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
