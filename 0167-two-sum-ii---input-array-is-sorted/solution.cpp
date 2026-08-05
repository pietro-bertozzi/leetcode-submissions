class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        for (int i = 0; i < n && numbers[i] <= target / 2; ++i) {
            int need = target - numbers[i];
            int l = i + 1, r = n - 1;
            while (l <= r) {
                int m = l + (r - l) / 2;
                if (numbers[m] < need) l = m + 1;
                else if (numbers[m] > need) r = m - 1;
                else return {i + 1, m + 1};
            }
        }
        return {};
    }
};
