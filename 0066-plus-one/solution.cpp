class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        bool nine = true;
        for (int i = n - 1; nine && i >= 0; --i) {
            if (digits[i] != 9) {
                digits[i]++;
                nine = false;
            } else digits[i] = 0;
        }
        if (nine) digits.insert(digits.begin(), 1);
        return digits;
    }
};
