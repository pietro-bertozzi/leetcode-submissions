class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        int result = tickets[k];
        for (int i = 0; i < k; ++i) result += min(tickets[i], tickets[k]);
        for (int i = k + 1; i < n; ++i) result += min(tickets[i], tickets[k] - 1);
        return result;
    }
};
