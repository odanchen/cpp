class StockSpanner {
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int cnt = 1;
        while (!monostack.empty() and monostack.top().first <= price) {
            cnt += monostack.top().second;
            monostack.pop();
        }
        monostack.push({price, cnt});
        return cnt;
    }
    stack<pair<int, int>> monostack;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
