class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> prices(cost.size() + 1);
        for (int i = 2; i < prices.size(); i++) {
            prices[i] = min(prices[i - 1] +  cost[i - 1], prices[i - 2] +  cost[i - 2]);
        }
        return prices.back();
    }
};
