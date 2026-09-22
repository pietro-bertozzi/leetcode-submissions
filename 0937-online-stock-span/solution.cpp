class StockSpanner {
private:
    vector<pair<int,int>> mono;

public:
    StockSpanner() {}

    int next(int price) {
        int span = 1;
        while (!mono.empty() && mono.back().first <= price) {
            span += mono.back().second;
            mono.pop_back();
        }
        mono.push_back({price, span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
