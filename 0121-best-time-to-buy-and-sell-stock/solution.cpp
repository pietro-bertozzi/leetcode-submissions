class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int result = 0, buy = prices[0];
        for (int i = 1; i < n; ++i) {
            result = max(prices[i] - buy, result);
            buy = min(prices[i], buy);
        }
        return result;
    }
};
