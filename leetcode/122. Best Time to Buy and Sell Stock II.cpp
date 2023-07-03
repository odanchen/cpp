class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for (int buy = 0; buy < prices.size(); buy++) {
            while(buy < prices.size() - 1 and prices[buy] > prices[buy + 1]) buy++; 
            int sell = buy + 1;
            while(sell < prices.size() - 1 and prices[sell] < prices[sell + 1]) sell++;
            if (sell < prices.size()) ans += prices[sell] - prices[buy];
            buy = sell;
        }
        return ans;
    }
};
