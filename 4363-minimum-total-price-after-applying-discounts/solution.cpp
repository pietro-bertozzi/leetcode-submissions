class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        double result = 0.0;
        sort(prices.begin(), prices.end(), greater<int>());
        sort(discounts.begin(), discounts.end(), greater<int>());
        int n = discounts.size();
        int m = prices.size();
        if (n <= m) {
            for (int i = 0; i < n; ++i) {
                result += (double) (prices[i] * (100 - discounts[i])) / 100;
            }
            for (int i = n; i < m; ++i) {
                result += (double) prices[i];
            }   
        } else {
            for (int i = 0; i < m; ++i) {
                result += (double) (prices[i] * (100 - discounts[i])) / 100;
            }
        }
        return result;
    }
};
