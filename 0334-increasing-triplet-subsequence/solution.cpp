class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX, second = INT_MAX;
        for (int n : nums) {
            if (n > second) return true;
            else if (n > first) second = n;
            else first = n;
        }
        return false;
    }
};
